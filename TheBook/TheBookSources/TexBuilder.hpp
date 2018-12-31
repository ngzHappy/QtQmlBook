﻿#pragma once

#include "the_book_global.hpp"

/*

keys :

章
:the_book_chapter[==[ $data$ ]==]

原样输出
:tex_raw[==[ $data$ ]==]

文本(进行特殊字符转换)
:text[==[ $data$ ]==]

*/

class TexBuilderPrivate;
class TexBuilder :
        public std::enable_shared_from_this<TexBuilder> {
    TexBuilderPrivate * const thisp;
public:

    TexBuilder();
    ~TexBuilder();

    /*设置输入文件名称*/
    void setInputFileName(const QString &);
    QString getInputFileName() const ;

    /*设置输出文件名称*/
    void setOutputFileName(const QString &);
    QString getOutputFileName() const;

    /*进行转换*/
    bool convert();

};




















