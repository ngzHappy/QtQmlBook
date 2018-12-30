#include "TestData.hpp"

TestData::TestData() {
    setData(trUtf8(u8R"(你好世界!)"));
}

QString TestData::getData() const {
    return mmmData;
}

void TestData::setData(const QString & arg) {
    if (arg == mmmData) {
        return;
    }
    mmmData = arg;
    dataChanged();
}














