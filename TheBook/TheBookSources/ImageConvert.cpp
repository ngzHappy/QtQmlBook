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

bool ImageConvert::convert() {

    QString varCommand;
    {
        QFileSelector varSelect{};
        auto varFileName =
            varSelect.select(getOutPutFileFullPath(qsl("the_book_image/command/sam2p.txt")));
        QFile varReadFile{ varFileName };
        if (!varReadFile.open(QIODevice::ReadOnly)) {
            return false;
        }
        InputStream varReadStream{ &varReadFile };
        varCommand =
            varReadStream.readAll().trimmed();
    }

    {
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
        clipImage(&varImage);
        varImage.save(output_image_full_path);
    }

    {
        output_image_relative_path =
            qsl("the_book_image/") +
            image_index +
            qsl(".eps");
        output_image_full_path =
            getOutPutFileFullPath(
                output_image_relative_path);
    }

    QProcess varProcess;
    varProcess.closeReadChannel(QProcess::StandardOutput);
    varProcess.start(
        varCommand,
        QStringList()
        << input_image_full_path
        << output_image_full_path);
    if (varProcess.waitForFinished(60'000)) {
        return 0 == varProcess.exitCode();
    } else {
        varProcess.terminate();
        return false;
    }

}
























