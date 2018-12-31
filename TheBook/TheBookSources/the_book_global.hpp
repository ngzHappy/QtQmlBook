#pragma once

#include <QtGui/QtGui>
#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>

#include <array>
#include <type_traits>
#include <exception>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <string>
#include <string_view>

using namespace std::string_view_literals;
using namespace std::chrono_literals;

static inline QString getOutPutFileFullPath(const QString & arg){
    const static QDir varDir{ THE_PROJECT_PWD_DIR };
    return varDir.absoluteFilePath(arg);
}

inline static void theBookThrow(
        const std::string_view &,
        const std::string_view &,
        const std::string_view &,
        int){
    throw QStringLiteral("some error!");
}

#ifndef qsl
#define qsl QStringLiteral
#endif

#ifndef qbl
#define qbl QByteArrayLiteral
#endif

#ifndef the_book_throw
#define the_book_throw(...) theBookThrow( __VA_ARGS__ , __FILE__,__func__,__LINE__ )
#endif








