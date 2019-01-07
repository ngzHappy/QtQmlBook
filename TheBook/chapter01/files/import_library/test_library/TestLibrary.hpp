#pragma once

#include <QtCore/qglobal.h>

#ifndef D_TEST_LIBRARY
#define TEST_LIBRARY_EXPORT Q_DECL_IMPORT
#else
#define TEST_LIBRARY_EXPORT Q_DECL_EXPORT
#endif

class TEST_LIBRARY_EXPORT TestClass {
public:
    TestClass();
    ~TestClass();
    void foo();
};










