#include "output_main_index.hpp"
#include "OutPutStream.hpp"

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
left=0.8cm,                %靠近装订线的边距
right=0.8cm,               %远离装订线的边距
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
\usepackage{tocbibind} %设置目录
\usepackage{tocloft}
\usepackage{multicol}

%%常见符号
\usepackage{wasysym} %
\usepackage{textcomp}%
\usepackage{pifont}  %

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

/*输出主文件目录*/
extern void output_main_index() try {

    output_setup_page_geometry_a4();
    output_setup_general_packages();
    out_put_setup_hyperref();

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

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\begin{document}




今天是个好天气




\end{document}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

)___1_");

} catch (...) {
    throw;
}





