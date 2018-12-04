#include <sstd_qt_and_qml_library.hpp>
#include "TestObject.hpp"

int main(int argc, char ** argv) {

    auto varApp = sstd_make_unique<sstd::Application>(argc, argv);

    auto varTestObject = sstd_make_shared< TestObject >();

    return QTest::qExec(varTestObject.get(), argc, argv);

}





