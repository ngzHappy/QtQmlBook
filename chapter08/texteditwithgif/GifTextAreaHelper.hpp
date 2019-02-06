#pragma once

#include <sstd_qt_and_qml_library.hpp>

class GifTextAreaHelper :
        public QQuickItem ,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(GifTextAreaHelper){
    Q_OBJECT
private:
    using Super = GifTextAreaHelper;
public:
    GifTextAreaHelper();
protected:
    void classBegin() override;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(GifTextAreaHelper);
};






















