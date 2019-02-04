#pragma once

#include "the_book_global.hpp"

template<typename T>
class BeforOutPutFileStream {
public:
    inline BeforOutPutFileStream() {
        static_cast<T *>(this)
            ->pppConstructStream(static_cast<T *>(
                this)->pppGetStream());
        this->_outPutHeader();
    }
    inline ~BeforOutPutFileStream() {
        {
            auto & o =
                *static_cast<T *>(this)->pppGetStream();
            for (int i = 0; i < 4; ++i) {
                o << endl;
            }
        }
        this->_outPutHeader();
    }
private:
    inline void _outPutHeader() {
        auto & o =
            *static_cast<T *>(this)->pppGetStream();
        /*输出头文件信息*/
        ::outputHeader(o);
    }
};

class OutPutFileStream :
    public QTextStream,
    public BeforOutPutFileStream<OutPutFileStream> {
    using Super = QTextStream;
public:

    template<typename ... Args>
    inline OutPutFileStream(Args && ... args) :
        Super(std::forward<Args>(args)...) {
    }

    template<typename T1>
    inline QTextStream & operator<<(T1 && arg) {
        QTextStream & varAns = *pppGetStream();
        varAns << std::forward<T1>(arg);
        return varAns;
    }

    inline operator QTextStream &() {
        return *this;
    }

    inline operator const QTextStream &() const & {
        return *this;
    }

private:
    inline QTextStream * pppGetStream() {
        return this;
    }
    static void pppConstructStream(QTextStream *);
    template<typename T>
    friend class ::BeforOutPutFileStream;
};
