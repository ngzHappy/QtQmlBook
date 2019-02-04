#pragma once

#include "the_book_global.hpp"

/*

keys :

原样输出
:tex_raw:[==[ $data$ ]==]

前言
:the_book_foreword:[ $data$ ]

章
:the_book_chapter:[ $data$ ]

文本(进行特殊字符转换)
:the_book_text:[ $data$ ]

*/

class TexBuilderPrivate;

class GlobalTexBuilder {
public:
    virtual ~GlobalTexBuilder();
    virtual QTextStream & getFigureIndex() const = 0;
    virtual QTextStream & getSourceIndex() const = 0;
    virtual QTextStream & getDirTreeSourceIndex() const = 0;
    virtual QTextStream & getCommandSourceIndex() const = 0;
    virtual QTextStream & getTableIndex() const = 0;
};

class TexBuilder :
    public std::enable_shared_from_this<TexBuilder> {
    TexBuilderPrivate * const thisp;
public:

    TexBuilder(GlobalTexBuilder * g = nullptr);
    ~TexBuilder();

    /*设置输入文件名称*/
    void setInputFileName(const QString &);
    QString getInputFileName() const;

    /*设置输出文件名称*/
    void setOutputFileName(const QString &);
    QString getOutputFileName() const;

    /*进行转换*/
    bool convert();

};
