#pragma once

#include <QtCore/qtextstream.h>
#include <QtCore/qtextcodec.h>

class InputStream :
        public QTextStream{
public:
    template<typename ... Args>
    InputStream(Args && ... args):
        QTextStream (std::forward<Args>(args)...){
#if defined (Q_OS_WIN)
        /*在Windows平台下强制使用UTF8编码读取*/
        auto varCodec = QTextCodec::codecForName(
                    QByteArrayLiteral("UTF-8"));
        if(this->codec()!=varCodec){
            this->setCodec(varCodec);
        }
#endif
    }

};







