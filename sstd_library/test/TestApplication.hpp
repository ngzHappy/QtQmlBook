#pragma once

#include <sstd_library.hpp>
#include <QtWidgets/qapplication.h>

#define _SSTD_B_ true
#define _SSTD_T_ TestApplication
class TestApplication :
        public QApplication ,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(TestApplication){
    Q_OBJECT
public:
    TestApplication(int,char **);
    virtual ~TestApplication();
private:
    using Super = QApplication;

};



