#include "TestObject.hpp"
#include <sstd_library.hpp>

#include <string_view>
using namespace std::string_view_literals;

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
        int value = 1;
    };

    /*静态检查，是否有语法错误*/
    inline void static_test() {
        static_assert(sizeof(StaticClassTest) == sizeof(int), "");
        static_test_1_sstd_memory_static_class_basic();
        static_test_1_sstd_memory_dynamic_class_basic();
        sstd::vector<int> var;
    }

}

namespace dynamic_test_ns {
    class DynamicClassTestBasic : public QObject,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(DynamicClassTestBasic) {
        SSTD_END_DEFINE_VIRTUAL_CLASS(DynamicClassTestBasic);
    };
    class DynamicClassTest : public DynamicClassTestBasic,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(DynamicClassTest) {
        SSTD_END_DEFINE_VIRTUAL_CLASS(DynamicClassTest);
    };
}

void TestObject::staticTest() {
    static_test_ns::static_test();
    {/*simple test new delete*/
        auto var = new int[32];
        var[12] = 3;
        delete var;
    }
    {
        auto var = new static_test_ns::StaticClassTest;
        QVERIFY(var->sstd_get_this_void() == var);
        QVERIFY(var->sstd_get_type_index() == typeid(static_test_ns::StaticClassTest));
        QVERIFY(var->sstd_get_type_info() == typeid(static_test_ns::StaticClassTest));
        QVERIFY(var->sstd_is_polymorphic() == false);
        QVERIFY(var->sstd_get_sstd_type_index() == sstd_type_id(*var));
        delete var;
    }
}

void TestObject::dynamicTest() {
    auto var = new dynamic_test_ns::DynamicClassTest;
    dynamic_test_ns::DynamicClassTestBasic * varBase = var;
    QVERIFY(varBase->sstd_get_this_void() == var);
    QVERIFY(varBase->sstd_get_type_index() == typeid(dynamic_test_ns::DynamicClassTest));
    QVERIFY(varBase->sstd_get_type_info() == typeid(dynamic_test_ns::DynamicClassTest));
    QVERIFY(varBase->sstd_is_polymorphic() == true);
    QVERIFY(varBase->sstd_get_sstd_type_index() == sstd_type_id(*var));
    QVERIFY(sstd_type_id(var) == sstd_type_id(*var));
    delete varBase;
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

namespace type_cast_test_ns {

    class A0 {
    public:
        virtual ~A0() {
        }
    };

    class A1 {
    public:
        virtual ~A1() {
        }
    };

    class A2 : public virtual A1 {
    public:
        virtual ~A2() {
        }
    };

    class A3 : public virtual A1 {
    public:
        virtual ~A3() {
        }
    };

    class A4 : public A0, public A2, public A3 {
    public:
        virtual ~A4() {
        }
    };

    class A5 : public A4 {
    public:
        virtual ~A5() {
        }
    };

    class A6 {
    public:
        virtual ~A6() {
        }
    };

}/**/

void TestObject::typeCastTest() {
    using namespace type_cast_test_ns;
    auto a5 = new A5;
    A0 * a0 = a5;
    A1 * a1 = a5;
    A2 * a2 = a5;
    A3 * a3 = a5;
    A4 * a4 = a5;

    QVERIFY(a5 == sstd_runtime_cast<A5>(a0));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a1));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a2));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a3));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a4));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a5));

    QVERIFY(a4 == sstd_runtime_cast<A4>(a0));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a1));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a2));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a3));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a4));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a5));

    QVERIFY(a3 == sstd_runtime_cast<A3>(a0));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a1));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a2));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a3));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a4));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a5));

    QVERIFY(a2 == sstd_runtime_cast<A2>(a0));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a1));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a2));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a3));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a4));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a5));

    QVERIFY(a1 == sstd_runtime_cast<A1>(a0));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a1));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a2));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a3));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a4));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a5));

    QVERIFY(a0 == sstd_runtime_cast<A0>(a0));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a1));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a2));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a3));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a4));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a5));

    QVERIFY(a5 == sstd_runtime_cast<A5>(a0));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a1));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a2));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a3));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a4));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a5));

    QVERIFY(a4 == sstd_runtime_cast<A4>(a0));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a1));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a2));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a3));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a4));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a5));

    QVERIFY(a3 == sstd_runtime_cast<A3>(a0));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a1));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a2));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a3));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a4));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a5));

    QVERIFY(a2 == sstd_runtime_cast<A2>(a0));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a1));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a2));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a3));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a4));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a5));

    QVERIFY(a1 == sstd_runtime_cast<A1>(a0));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a1));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a2));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a3));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a4));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a5));

    QVERIFY(a0 == sstd_runtime_cast<A0>(a0));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a1));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a2));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a3));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a4));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a5));

    QVERIFY(nullptr == sstd_runtime_cast<A6>(a0));
    QVERIFY(nullptr == sstd_runtime_cast<A6>(a1));
    QVERIFY(nullptr == sstd_runtime_cast<A6>(a2));
    QVERIFY(nullptr == sstd_runtime_cast<A6>(a3));
    QVERIFY(nullptr == sstd_runtime_cast<A6>(a4));
    QVERIFY(nullptr == sstd_runtime_cast<A6>(a5));

}

namespace type_cast_test_ns1 {

    class A0 : SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(A0) {
    public:
        virtual ~A0() {
        }
        SSTD_END_DEFINE_VIRTUAL_CLASS(A0);
    };

    class A1 : SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(A1) {
    public:
        virtual ~A1() {
        }
        SSTD_END_DEFINE_VIRTUAL_CLASS(A1);
    };

    class A2 : public virtual A1,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(A2) {
    public:
        virtual ~A2() {
        }
        SSTD_END_DEFINE_VIRTUAL_CLASS(A2);
    };

    class A3 : public virtual A1,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(A3) {
    public:
        virtual ~A3() {
        }
        SSTD_END_DEFINE_VIRTUAL_CLASS(A3);
    };

    class A4 : public A0, public A2, public A3,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(A4){
    public:
        virtual ~A4() {
        }
        SSTD_END_DEFINE_VIRTUAL_CLASS(A4);
    };

    static int globalA5Count{ 0 };
    class A5 : public A4,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(A5){
    public:
        A5() {
            ++globalA5Count;
        }
        virtual ~A5() {
            --globalA5Count;
        }
        SSTD_END_DEFINE_VIRTUAL_CLASS(A5);
    };

    class A6 : SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(A6) {
    public:
        virtual ~A6() {
        }
        SSTD_END_DEFINE_VIRTUAL_CLASS(A6);
    };

}/**/

void TestObject::typeCastTest1() {
    using namespace type_cast_test_ns1;
    auto a5 = new A5;
    A0 * a0 = a5;
    A1 * a1 = a5;
    A2 * a2 = a5;
    A3 * a3 = a5;
    A4 * a4 = a5;

    QVERIFY(a5 == sstd_runtime_cast<A5>(a0));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a1));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a2));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a3));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a4));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a5));

    QVERIFY(a4 == sstd_runtime_cast<A4>(a0));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a1));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a2));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a3));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a4));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a5));

    QVERIFY(a3 == sstd_runtime_cast<A3>(a0));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a1));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a2));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a3));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a4));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a5));

    QVERIFY(a2 == sstd_runtime_cast<A2>(a0));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a1));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a2));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a3));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a4));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a5));

    QVERIFY(a1 == sstd_runtime_cast<A1>(a0));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a1));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a2));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a3));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a4));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a5));

    QVERIFY(a0 == sstd_runtime_cast<A0>(a0));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a1));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a2));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a3));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a4));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a5));

    QVERIFY(a5 == sstd_runtime_cast<A5>(a0));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a1));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a2));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a3));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a4));
    QVERIFY(a5 == sstd_runtime_cast<A5>(a5));

    QVERIFY(a4 == sstd_runtime_cast<A4>(a0));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a1));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a2));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a3));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a4));
    QVERIFY(a4 == sstd_runtime_cast<A4>(a5));

    QVERIFY(a3 == sstd_runtime_cast<A3>(a0));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a1));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a2));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a3));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a4));
    QVERIFY(a3 == sstd_runtime_cast<A3>(a5));

    QVERIFY(a2 == sstd_runtime_cast<A2>(a0));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a1));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a2));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a3));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a4));
    QVERIFY(a2 == sstd_runtime_cast<A2>(a5));

    QVERIFY(a1 == sstd_runtime_cast<A1>(a0));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a1));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a2));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a3));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a4));
    QVERIFY(a1 == sstd_runtime_cast<A1>(a5));

    QVERIFY(a0 == sstd_runtime_cast<A0>(a0));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a1));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a2));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a3));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a4));
    QVERIFY(a0 == sstd_runtime_cast<A0>(a5));

    QVERIFY(nullptr == sstd_runtime_cast<A6>(a0));
    QVERIFY(nullptr == sstd_runtime_cast<A6>(a1));
    QVERIFY(nullptr == sstd_runtime_cast<A6>(a2));
    QVERIFY(nullptr == sstd_runtime_cast<A6>(a3));
    QVERIFY(nullptr == sstd_runtime_cast<A6>(a4));
    QVERIFY(nullptr == sstd_runtime_cast<A6>(a5));

    delete a5;
}

void TestObject::dynamicObjectTest() {

    using namespace type_cast_test_ns1;

    {
        auto var = sstd_make_unique<sstd_function_stack>();

        var->sstd_create_data_in_this_class<A5>();
        QVERIFY(globalA5Count == 1);
        auto varA5_1 = var->sstd_create_named_data_in_this_class<A5>("a5"sv);
        QVERIFY(globalA5Count == 2);
        auto varA2_1 = var->sstd_find_named_data_in_this_class<A2>("a5"sv);
        QVERIFY(globalA5Count == 2);

        QVERIFY(varA2_1);
        QVERIFY(dynamic_cast<A5 *>(varA2_1) == varA5_1);
        QVERIFY(nullptr == var->sstd_find_named_data_in_this_class<int>("a5"sv));
    }

    QVERIFY(globalA5Count == 0);

    {
        auto var = sstd_make_unique<sstd_function_stack>();
        auto varState = var->sstd_get_class_state();
        std::unique_lock varLock { varState };

        var->sstd_create_data_in_this_class_thread_safe<A5>();
        QVERIFY(globalA5Count == 1);
        auto varA5_1 = var->sstd_create_named_data_in_this_class_thread_safe<A5>("a5"sv);
        QVERIFY(globalA5Count == 2);
        auto varA2_1 = var->sstd_find_named_data_in_this_class_thread_safe<A2>("a5"sv);
        QVERIFY(globalA5Count == 2);

        QVERIFY(varA2_1);
        QVERIFY(dynamic_cast<A5 *>(varA2_1) == varA5_1);
        QVERIFY(nullptr == var->sstd_find_named_data_in_this_class_thread_safe<int>("a5"sv));
    }

    QVERIFY(globalA5Count == 0);

}

extern void testFiber1();
void TestObject::testFiber() {
    testFiber1();
}


