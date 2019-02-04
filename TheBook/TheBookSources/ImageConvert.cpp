#include "ImageConvert.hpp"


bool ImageConvert::needConvert() const {

    if (input_image_full_path.endsWith(
        QStringLiteral(".pdf"),
        Qt::CaseInsensitive)) {
        return false;
    }

    if (input_image_full_path.endsWith(
        QStringLiteral(".eps"),
        Qt::CaseInsensitive)) {
        return false;
    }

    return true;
}

inline static void clipImage(
    QImage * arg1) {

    if (arg1->width() < 0) {
        return;
    }

    if (arg1->height() < 0) {
        return;
    }

    const auto varTmp =
        arg1->convertToFormat(QImage::Format_RGBA8888);

    *arg1 =
        varTmp.copy(1, 1,
            std::max(1, varTmp.width() - 2),
            std::max(1, varTmp.height() - 2));

}

extern std::atomic< std::size_t > & countConvertImageToPdf() {
    static std::atomic< std::size_t > varAns{ 0 };
    return varAns;
}

/*将图片转为pdf*/
/*#include <QtGui/QtGui>*/
static inline bool convert_image_to_pdf(
    const QImage & argImage,
    const QString argPdfFileName) {

    const auto varImage
        = argImage.convertToFormat(QImage::Format_RGBA8888_Premultiplied);

    if (varImage.height() < 1) {
        return false;
    }
    if (varImage.width() < 1) {
        return false;
    }

    /* For example,
     * A4 is defined by the standard as 210mm x 297mm,
     * 8.27in x 11.69in,
     * or 595pt x 842pt.*/

     /*460大概是16.2cm*/
    auto varImgageWidth = 460;
    auto varImageHeigth = 460;

    /*限制图片的最大长或宽...*/
    if (varImage.height() > varImage.width()) {/*图片的高度大于长度...*/
        const auto varR = double(varImage.width())
            / double(varImage.height());
        /*调整宽度*/
        varImgageWidth = static_cast<int>(0.5 +
            varImageHeigth * varR);
    } else if (varImage.height() < varImage.width()) {/*图片的高度大于宽度...*/
        const auto varR = double(varImage.height())
            / double(varImage.width());
        /*调整高度*/
        varImageHeigth = static_cast<int>(0.5 +
            varImgageWidth * varR);
    }

    /*打开写文件*/
    QFile varPDFFile{ argPdfFileName };
    if (false == varPDFFile.open(QIODevice::WriteOnly)) {
        return false;
    }

    QPdfWriter varWriter{ &varPDFFile };

    {/*设置文件参数*/
        varWriter.setMargins({ 0,0,0,0 });
        /*设置分辨率*/
        varWriter.setResolution(720)/*每英寸像素点数DPI*/;
        /*设置pdf文档大小*/
        const QPageSize varSize{/*QSize是72 dpi时的值*/
            QSize{varImgageWidth,varImageHeigth} ,QPageSize::Point/*72*/ };
        varWriter.setPageSize(varSize);
    }

    /*写文件*/
    QPainter varPainter{ &varWriter };
    /*获得pdf文件真实像素大小*/
    const auto varSizeOfViewPort =
        varPainter.viewport().size();
    /*将图片绘制到pdf文件*/
    varPainter.drawImage(0, 0,
        varImage.scaled(
            varSizeOfViewPort,
            Qt::IgnoreAspectRatio,
            Qt::SmoothTransformation));

    return true;

}

namespace {
    class Run : public QRunnable {
        const QImage inputImage;
        const QString outputImagePath;
        volatile bool isDestory{ false };
    public:
        inline Run(const QImage & a, const QString & b) :
            inputImage(a),
            outputImagePath(b) {
            ++countConvertImageToPdf();
        }
        inline void run() override {
            convert_image_to_pdf(inputImage, outputImagePath);
            destory();
        }
        inline void destory() {
            if (isDestory) {
                return;
            }
            isDestory = true;
            --countConvertImageToPdf();
        }
        inline ~Run() {
            destory();
        }
    };
}/**/

bool ImageConvert::convert() {

    {
        /*打开输入图片*/
        QImage varImage{
            input_image_full_path
        };
        if (varImage.isNull()) {
            return false;
        }
        {
            output_image_relative_path =
                qsl("the_book_image/") +
                image_index +
                qsl(".bmp");
            output_image_full_path =
                getOutPutFileFullPath(
                    output_image_relative_path);
            input_image_full_path = output_image_full_path;
        }
        /*处理图片并保存*/
        clipImage(&varImage);
        varImage.save(output_image_full_path);
    }

    {
        output_image_relative_path =
            qsl("the_book_image/") +
            image_index +
            qsl(".pdf");
        output_image_full_path =
            getOutPutFileFullPath(
                output_image_relative_path);
    }

    /*将图片转为pdf*/
    QThreadPool::globalInstance()->start(
        new Run{ QImage(input_image_full_path), output_image_full_path });

    return true;

}
