#include "TestObject.hpp"
#include <sstd_library.hpp>

TestObject::TestObject() {

}

void TestObject::initTestCase() {

}

void TestObject::cleanupTestCase() {

}

namespace static_test_ns {

    inline void static_test_1_sstd_memory_static_class_basic() {
        auto var = new _1_sstd_memory_static_class_basic;
        delete var;
    }

    inline void static_test_1_sstd_memory_dynamic_class_basic() {
        auto var = new _1_sstd_memory_dynamic_class_basic;
        delete var;
    }

    class StaticClassTest {
    public:
        SSTD_DEFINE_STATIC_CLASS(StaticClassTest);
        int value=1;
    };

    /*静态检查，是否有语法错误*/
    inline void static_test() {
        static_assert(sizeof(StaticClassTest) == sizeof(int), "");
        static_test_1_sstd_memory_static_class_basic();
        static_test_1_sstd_memory_dynamic_class_basic();
    }
}

namespace dynamic_test_ns {
    class DynamicClassTest : SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(DynamicClassTest) {
        SSTD_END_DEFINE_VIRTUAL_CLASS(DynamicClassTest);
    };
}

void TestObject::staticTest() {
    static_test_ns::static_test();
    {
        auto var = new static_test_ns::StaticClassTest;
        QVERIFY(var->sstd_get_this_void() == var);
        QVERIFY(var->sstd_get_type_index() == typeid(static_test_ns::StaticClassTest));
        QVERIFY(var->sstd_get_type_info() == typeid(static_test_ns::StaticClassTest));
        QVERIFY(var->sstd_is_polymorphic() == false);
    }
}

void TestObject::dynamicTest(){
    auto var = new dynamic_test_ns::DynamicClassTest;
    QVERIFY(var->sstd_get_this_void() == var);
    QVERIFY(var->sstd_get_type_index() == typeid(dynamic_test_ns::DynamicClassTest));
    QVERIFY(var->sstd_get_type_info() == typeid(dynamic_test_ns::DynamicClassTest));
    QVERIFY(var->sstd_is_polymorphic() == true);
}

void TestObject::sstdTypeIndexTest() {
    {
        int varInt = 1;
        QCOMPARE(sstd_type_id<int>(), sstd_type_id(varInt));
    }
    {
        static_test_ns::StaticClassTest var;
        QCOMPARE(sstd_type_id<static_test_ns::StaticClassTest>(), sstd_type_id(var));
    }
    {
        dynamic_test_ns::DynamicClassTest var;
        QCOMPARE(sstd_type_id<dynamic_test_ns::DynamicClassTest>(), sstd_type_id(var));
    }
}




