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
























