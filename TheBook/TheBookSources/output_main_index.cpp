#include "output_main_index.hpp"

extern void output_main_index() try {

    QFile varFile{ getOutPutFileFullPath( qsl("main_index.tex") ) };
    if( varFile.open( QIODevice::WriteOnly ) == false ){
        the_book_throw("can not open file main_index.tex"sv);
    }

} catch( ... ) {
    throw;
}

