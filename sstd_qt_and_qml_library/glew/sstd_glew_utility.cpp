#define _SSTD_HAS_GLEW_0_1

#include "GLSSTD/glew.h"
#include "sstd_glew_utility.hpp"

namespace sstd {


    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint createTexture(QImage arg){

        const auto varImage =
                arg.convertToFormat( QImage::Format_RGBA64 );

        if( varImage.isNull() ){
            return 0;
        }

        //glCreateTextures();



        return 0;
    }

    EXPORT_SSTD_QT_AND_QML_LIBRARY void updateTexture(GLuint,QImage){}

}/*namespace sstd*/















