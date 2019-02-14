#pragma once

#include <sstd_qt_and_qml_library.hpp>

class MyValue {
    Q_GADGET
private:
    double mmmX{ 0 };
    double mmmY{ 0 };
public:
    Q_INVOKABLE inline double getX() const;
    Q_INVOKABLE inline double getY() const;
    Q_INVOKABLE inline void setX(double arg);
    Q_INVOKABLE inline void setY(double arg);
public:
    inline MyValue() = default;
    inline MyValue(const MyValue &) = default;
    inline MyValue(MyValue &&) = default;
    inline MyValue&operator=(const MyValue &) = default;
    inline MyValue&operator=(MyValue &&) = default;
    MyValue(double, double);
public:
    Q_INVOKABLE inline bool operator==(const MyValue &) const;
private:
    SSTD_DEFINE_STATIC_CLASS(MyValue);
};

inline double MyValue::getX() const {
    return mmmX;
}

inline double MyValue::getY() const {
    return mmmY;
}

inline void MyValue::setX(double arg) {
    mmmX = arg;
}

inline void MyValue::setY(double arg) {
    mmmY = arg;
}

inline bool MyValue::operator==(const MyValue & arg) const {
    return (mmmX == arg.mmmX) && (mmmY == arg.mmmY);
}

Q_DECLARE_METATYPE(MyValue)













