#pragma once

#include <sstd_library.hpp>
#include <QtTest/qtest.h>

class TestObject :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(TestObject){
    Q_OBJECT
public:
    TestObject();
private slots:
    void initTestCase();
    void cleanupTestCase();
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(TestObject);
};


