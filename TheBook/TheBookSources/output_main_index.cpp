#include "output_main_index.hpp"
#include "OutPutStream.hpp"
#include "TexBuilder.hpp"

/*设置页面*/
inline void output_setup_page_geometry_a4() {
    QFile varFile{ getOutPutFileFullPath(qsl("setup_page_geometry_a4.tex")) };
    if (varFile.open(QIODevice::WriteOnly) == false) {
        the_book_throw("can not open file setup_page_geometry_a4.tex"sv);
    }
    OutPutFileStream varStream{ &varFile };

    varStream << qsl(R"__1__(

\usepackage{xcolor}        %导入包xcolor
\usepackage[
a4paper,
left=2.1cm,                %靠近装订线的边距
right=1.5cm,               %远离装订线的边距
top=1.3cm,
bottom=1cm,
headheight=1.3cm,
headsep=0.1cm,
marginparsep=0.1cm,
marginparwidth=0.1cm
]{geometry}                %导入包geometry

)__1__");

}

/*导入常用包*/
inline static void output_setup_general_packages() {
    QFile varFile{ getOutPutFileFullPath(qsl("setup_general_packages.tex")) };
    if (varFile.open(QIODevice::WriteOnly) == false) {
        the_book_throw("can not open file setup_page_geometry_a4.tex"sv);
    }
    OutPutFileStream varStream{ &varFile };

    varStream << qsl(R"__1__(

 %导入常用包
\usepackage{graphicx}
\usepackage{float}
\usepackage{amsmath}
\usepackage{cite}
\usepackage{caption}
\usepackage{titlesec}
\usepackage{chngcntr}
\usepackage{setspace}
\usepackage{tocbibind}  %设置目录
\usepackage{tocloft}
\usepackage{multicol}

%%常见符号
\usepackage{wasysym}    %
\usepackage{textcomp}   %
\usepackage{pifont}     %

\usepackage{color}
\definecolor{colorbackgroundthisproject}{rgb}{1,1,1} %页面背景颜色
\definecolor{colortextthisproject}{rgb}{0,0,0}       %文字颜色
%设置页面颜色
\pagecolor{colorbackgroundthisproject}
%设置字体颜色
\color{colortextthisproject}

\usepackage{xhfill}
\usepackage{times}

)__1__");


}

/*设置输出pdf格式*/
inline static void out_put_setup_hyperref() {

    QFile varFile{ getOutPutFileFullPath(qsl("setup_hyperref.tex")) };
    if (varFile.open(QIODevice::WriteOnly) == false) {
        the_book_throw("can not open file setup_hyperref.tex"sv);
    }
    OutPutFileStream varStream{ &varFile };

    varStream << qsl(R"__1__(

%设置输出pdf格式
\usepackage[
    colorlinks=true ,
    %bookmarks=true,
    %bookmarksopen=false,
    %pdfpagemode=FullScreen,
    %pdfstartview=Fit,
    bookmarksnumbered=true,
    pdftitle={Qml} ,       %标题
    pdfauthor={Qml} ,      %作者
    pdfsubject={Qml} ,     %主题
    pdfkeywords={Qml} ,    %关键字
    linkcolor=colortextthisproject
]{hyperref}


)__1__");

}

inline static void output_foreword() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("foreword/foreword.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("foreword/foreword.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(foreword/foreword.tex)"sv);
        }
    }
}

inline static void output_chapter_01() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/chapter01.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/chapter01.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/chapter01.tex)"sv);
        }
    }
}

inline static void output_chapter_02() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter02/chapter02.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter02/chapter02.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter02/chapter02.tex)"sv);
        }
    }
}

inline static void output_chapter_03() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter03/chapter03.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter03/chapter03.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter03/chapter03.tex)"sv);
        }
    }
}

inline static void output_chapter_04() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter04/chapter04.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter04/chapter04.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter04/chapter04.tex)"sv);
        }
    }
}

inline static void output_chapter_05() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter05/chapter05.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter05/chapter05.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter05/chapter05.tex)"sv);
        }
    }
}

inline static void output_chapter_06() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter06/chapter06.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter06/chapter06.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter06/chapter06.tex)"sv);
        }
    }
}

inline static void output_chapter_07() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter07/chapter07.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter07/chapter07.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter07/chapter07.tex)"sv);
        }
    }
}

inline static void output_chapter_08() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter08/chapter08.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter08/chapter08.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter08/chapter08.tex)"sv);
        }
    }
}

inline static void output_chapter_09() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter09/chapter09.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter09/chapter09.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter09/chapter09.tex)"sv);
        }
    }
}

inline static void output_chapter_10() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter10/chapter10.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter10/chapter10.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter10/chapter10.tex)"sv);
        }
    }
}

#ifdef _DEBUG
extern void test_this();
#endif

/*输出主文件目录*/
extern void output_main_index() try {

#ifdef _DEBUG
    test_this();
#endif

    output_setup_page_geometry_a4();
    output_setup_general_packages();
    out_put_setup_hyperref();

    output_foreword();
    output_chapter_01();
    output_chapter_02();
    output_chapter_03();
    output_chapter_04();
    output_chapter_05();
    output_chapter_06();
    output_chapter_07();
    output_chapter_08();
    output_chapter_09();
    output_chapter_10();

    QFile varFile{ getOutPutFileFullPath(qsl("main_index.tex")) };
    if (varFile.open(QIODevice::WriteOnly) == false) {
        the_book_throw("can not open file main_index.tex"sv);
    }

    OutPutFileStream varStream{ &varFile };

    varStream << qsl(R"___1_(

\documentclass[hyperref,UTF8]{ctexbook}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\input{setup_page_geometry_a4}                        %设置纸张大小，页边距
\input{setup_general_packages}                        %导入常用包，设置颜色
\input{setup_hyperref}                                %设置超链接，控制pdf元数据

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%常量

\title{Qt Quick入门精选}                              %书籍名称
\author{Good Luck}                                    %作者名

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\begin{document}

\maketitle                        %生成封面

\input{foreword/foreword.tex}     %前言
\input{chapter01/chapter01.tex}   %第一章
\input{chapter02/chapter02.tex}   %第二章
\input{chapter03/chapter03.tex}   %第三章
\input{chapter04/chapter04.tex}   %第四章
\input{chapter05/chapter05.tex}   %第五章
\input{chapter06/chapter06.tex}   %第六章
\input{chapter07/chapter07.tex}   %第七章
\input{chapter08/chapter08.tex}   %第八章
\input{chapter09/chapter09.tex}   %第九章
\input{chapter10/chapter10.tex}   %第十章


\end{document}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

)___1_");

} catch (...) {
    throw;
}





