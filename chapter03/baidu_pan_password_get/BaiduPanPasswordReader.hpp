#pragma once

#include <sstd_qt_and_qml_library.hpp>

class BaiduPanPasswordReader :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(BaiduPanPasswordReader) {
    Q_OBJECT
public:
    BaiduPanPasswordReader();
public:
    Q_SLOT void openFile(int);
    Q_SLOT void moveToStart();
    Q_SLOT QString getNext();
    Q_SLOT bool isEndl() const;
    Q_SLOT void setMaximumBlockCount(QQuickTextDocument *);
private:
    sstd::intrusive_ptr<sstd_intrusive_ptr_basic> thisp;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(BaiduPanPasswordReader);
};
