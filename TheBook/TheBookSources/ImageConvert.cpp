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

void drawImageBorder(
    QImage * arg1,
    int width,
    const QColor & color) {

    auto varTmpImage =
        arg1->convertToFormat(QImage::Format::Format_RGBA8888);
    QImage * arg = &varTmpImage;

    class Color {
    public:
        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
        std::uint8_t a;
    };

    const Color varColor{
        static_cast<std::uint8_t>(color.red() & 255) ,
        static_cast<std::uint8_t>(color.green() & 255) ,
        static_cast<std::uint8_t>(color.blue() & 255) ,
        static_cast<std::uint8_t>(color.alpha() & 255) };

    const auto varSkip = arg->bytesPerLine();
    auto varBeginOfTheImage = arg->bits();
    auto varCurrentLine =
        reinterpret_cast<Color *>(varBeginOfTheImage);
    auto varCurrentLineBegin = varBeginOfTheImage;

    const auto varImageHeight = arg->height();
    const auto varImageWidth = arg->width();
    const auto varLeftLimit = width;
    const auto varRightLimit = varImageWidth > width ? (varImageWidth - width) : 0;
    const auto varTopLimit = width;
    const auto varBottomLimit = varImageHeight > width ? (varImageHeight - width) : 0;

    for (
        int varLineCount = 0;
        varLineCount < varImageHeight;
        ++varLineCount,
        varCurrentLineBegin += varSkip,
        varCurrentLine = reinterpret_cast<Color *>(varCurrentLineBegin)) {

        assert(varCurrentLineBegin == arg->constScanLine(varLineCount));

        if ((varLineCount < varTopLimit) || (varLineCount >= varBottomLimit)) {
            const auto varEnd = varCurrentLine + varImageWidth;
            for (auto varPos = varCurrentLine; varPos < varEnd; ++varPos) {
                *varPos = varColor;
            }
        } else for (int varColumnCount = 0;
            varColumnCount < varImageWidth;
            ++varColumnCount) {
            if ((varColumnCount < varLeftLimit) || (varColumnCount >= varRightLimit)) {
                auto varPos =
                    varCurrentLine + varColumnCount;
                *varPos = varColor;
            }
        }

    }

    *arg1 = *arg;

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
                qsl(".png");
            output_image_full_path =
                getOutPutFileFullPath(
                    output_image_relative_path);
            input_image_full_path = output_image_full_path;
        }
        drawImageBorder(&varImage, 1, QColor(253, 255, 255, 255));
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
























