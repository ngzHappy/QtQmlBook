#pragma once

#include <QtCore/qobject.h>
#include <QtTest/qtest.h>

class TestObject : public QObject {
    Q_OBJECT
public:
    TestObject();
private slots:
    void initTestCase();
    void staticTest();
    void dynamicTest();
    void sstdTypeIndexTest();
    void typeCastTest();
    void typeCastTest1();
    void dynamicObjectTest();
    void cleanupTestCase();
};







