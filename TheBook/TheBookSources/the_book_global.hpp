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

template <typename T,typename = void>
inline static void outputHeader(T && o ){
    o << qsl(R"(%使用xelatex编译)")<<endl;
    o << qsl(R"(%版权所有，翻版必究)")<<endl;

    {
        const static auto varCurrnetData = QDate::currentDate();
        o << qsl(R"( )") << varCurrnetData.year()  << qsl(R"( 年)")  ;
        o << qsl(R"( )") << varCurrnetData.month() << qsl(R"( 月)")  ;
        o << qsl(R"( )") << varCurrnetData.day() << qsl(R"( 日)")  ;
    }

    {
        const static auto varCurrentTime = QTime::currentTime();
        o << qsl(R"( )") << varCurrnetData.year()  << qsl(R"( )")  ;
        o << qsl(R"( )") << varCurrnetData.month() << qsl(R"( 月)")  ;
        o << qsl(R"( )") << varCurrnetData.day() << qsl(R"( 日)")  ;
    }

    o << endl ;
    o << endl ;
    o << endl ;

}






