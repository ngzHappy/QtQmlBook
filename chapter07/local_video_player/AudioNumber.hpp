#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include <boost/integer/common_factor_rt.hpp>

class AudioNumber {
public:
    std::int64_t num{ 0 };
    std::int64_t den{ 1'000'000 };
    inline constexpr AudioNumber changeDen(std::int64_t v) const {
        if (v == den) {
            return *this;
        }
        if (v > den) {
            assert((v%den) == 0);
            return { (v / den) * num ,v };
        }
        assert((den%v) == 0);
        return { num / (den / v) , v };
    }
    inline constexpr double getValue() const {
        if (num == 0) {
            return 0;
        }
        if (den == 0) {
            return 0;
        }
        return double(num) / double(den);
    }
private:
    SSTD_DEFINE_STATIC_CLASS(AudioNumber);
};

inline AudioNumber operator+(const AudioNumber & l, const AudioNumber & r) {
    assert(l.den > 0);
    assert(r.den > 0);
    if (l.den == r.den) {
        return { l.num + r.num , l.den };
    }
    const auto varNewDen = boost::integer::lcm(l.den, r.den);
    const auto varNewLeft = l.changeDen(varNewDen);
    const auto varNewRight = r.changeDen(varNewDen);
    return { varNewLeft.num + varNewRight.num , varNewDen };
}

inline AudioNumber operator-(const AudioNumber & l, const AudioNumber & r) {
    assert(l.den > 0);
    assert(r.den > 0);
    if (l.den == r.den) {
        return { l.num - r.num , l.den };
    }
    const auto varNewDen = boost::integer::lcm(l.den, r.den);
    const auto varNewLeft = l.changeDen(varNewDen);
    const auto varNewRight = r.changeDen(varNewDen);
    return { varNewLeft.num - varNewRight.num , varNewDen };
}

inline constexpr AudioNumber operator*(const AudioNumber & l, std::int64_t n) {
    return { l.num * n , l.den };
}

inline constexpr AudioNumber operator/(const AudioNumber & l, std::int64_t n) {
    return { l.num / n , l.den };
}

#ifndef __MUSIC_NUMBER_OP
#define __MUSIC_NUMBER_OP(_SSTD_OP_) \
inline bool operator _SSTD_OP_ ( const AudioNumber & l,const AudioNumber & r ){ \
    assert(l.den>0); \
    assert(r.den>0); \
    if( l.den == r.den ){ \
        return l.num _SSTD_OP_ r.num ; \
    } \
    const auto varNewDen = boost::integer::lcm(l.den,r.den); \
    const auto varNewLeft = l.changeDen(varNewDen); \
    const auto varNewRight = r.changeDen(varNewDen); \
    return varNewLeft.num _SSTD_OP_ varNewRight.num ; \
} \
static_assert(true)

#endif

__MUSIC_NUMBER_OP(> );
__MUSIC_NUMBER_OP(>= );
__MUSIC_NUMBER_OP(< );
__MUSIC_NUMBER_OP(<= );
__MUSIC_NUMBER_OP(== );
__MUSIC_NUMBER_OP(!= );










