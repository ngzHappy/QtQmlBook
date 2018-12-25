#include "MusicNumber.hpp"

#if defined(_DEBUG)

#include <QtCore/qcoreapplication.h>
inline static void test_this() {

    {
        MusicNumber a{ 1,2 };
        MusicNumber b{ 7,8 };
        MusicNumber c = a + b;
        assert(c.num == 11);
        assert(c.den == 8);
    }

    {
        MusicNumber a{ 1,2 };
        MusicNumber b = a * 11;
        assert(b.den == 2);
        assert(b.num == 11);
    }

    {
        MusicNumber a{ 1,2 };
        assert(a == a);
        MusicNumber b{ 1,3 };
        assert(a > b);
    }


}
Q_COREAPP_STARTUP_FUNCTION(test_this)


#endif


















