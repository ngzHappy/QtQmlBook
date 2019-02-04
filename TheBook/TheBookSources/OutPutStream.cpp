#include "OutPutStream.hpp"

void OutPutFileStream::pppConstructStream(QTextStream * arg) {
    arg->setCodec(QTextCodec::codecForName(qbl("utf-8")));
    arg->setGenerateByteOrderMark(true);
}
