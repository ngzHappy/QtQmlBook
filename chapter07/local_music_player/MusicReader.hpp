#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include "MusicInformation.hpp"
#include "MusicFrame.hpp"
#include "MusicNumber.hpp"

class _MusicReaderPrivate;
class MusicReader :
    public virtual sstd_intrusive_ptr_basic ,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MusicReader) {
public:
    MusicReader();
public:
    /*打开*/
    bool open(const QString &);
    /*获得媒体信息*/
    sstd::intrusive_ptr< const MusicInformation > information() const;
    /*定位*/
    bool seek(MusicNumber);
    /*开始读取*/
    void start(int = 0/*音轨编号*/);
    /*获得下一段音频*/
    sstd::intrusive_ptr< const MusicFrame > readNext();
    /*关闭*/
    void close();
public:
    ~MusicReader();
private:
    _MusicReaderPrivate * mmmPrivate{ nullptr };
    inline _MusicReaderPrivate * getThisPrivate();
    inline _MusicReaderPrivate * getThisPrivate() const;
    void pppDestoryThisPrivate();
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MusicReader);
};

inline _MusicReaderPrivate * MusicReader::getThisPrivate() {
    return mmmPrivate;
}

inline _MusicReaderPrivate * MusicReader::getThisPrivate() const {
    return mmmPrivate;
}






