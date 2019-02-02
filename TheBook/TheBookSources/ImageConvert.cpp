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

/*将图片转为pdf*/
static inline bool convert_image_to_pdf(const QImage & argImage, const QString argPdfFileName) {

    const auto
        varImage = argImage.convertToFormat(QImage::Format_RGBA8888_Premultiplied);

    /* For example,
     * A4 is defined by the standard as 210mm x 297mm,
     * 8.27in x 11.69in,
     * or 595pt x 842pt.*/

     /*宽度大概是16.2cm*/
    const constexpr auto varImgageWidth = 460;
    /*根据宽度计算高度*/
    const auto varImageHeigth = static_cast<int>(0.5 +
        varImgageWidth *
        double(varImage.height())
        / double(varImage.width()));

    /*打开写文件*/
    QFile varPDFFile{ argPdfFileName };
    if (false == varPDFFile.open(QIODevice::WriteOnly)) {
        return false;
    }

    QPdfWriter varWriter{ &varPDFFile };

    {/*设置文件参数*/
        varWriter.setMargins({ 0,0,0,0 });
        varWriter.setResolution(720)/*每英寸像素点数*/;
        const QPageSize varSize{
            QSize{varImgageWidth,varImageHeigth} ,QPageSize::Point/*72*/ };
        varWriter.setPageSize(varSize);
    }

    /*写文件*/
    QPainter varPainter{ &varWriter };
    const auto varSizeOfViewPort =
        varPainter.viewport().size();
    varPainter.drawImage(0, 0,
        varImage.scaled(
            varSizeOfViewPort,
            Qt::IgnoreAspectRatio,
            Qt::SmoothTransformation));

    return true;

}

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
    return convert_image_to_pdf(
        QImage(input_image_full_path), 
        output_image_full_path);

}
























