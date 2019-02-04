#pragma once

#include "the_book_global.hpp"

class ImageConvert {
    QString input_image_full_path;
    QString output_image_full_path;
    QString output_image_relative_path;
    QString image_index;
public:
    inline ImageConvert(const QString & aindex,
        const QString & binput) {
        image_index = aindex;
        input_image_full_path = binput;
    }
    bool needConvert() const;
    bool convert();
    inline QString getRelativePath() const {
        return output_image_relative_path;
    }
};
