#include "output_main_index.hpp"

/*设置页面*/
inline void output_setup_page_geometry_a4() {
    QFile varFile{ getOutPutFileFullPath(qsl("setup_page_geometry_a4.tex")) };
    if (varFile.open(QIODevice::WriteOnly) == false) {
        the_book_throw("can not open file setup_page_geometry_a4.tex"sv);
    }
    QTextStream varStream{ &varFile };
    varStream.setCodec(QTextCodec::codecForName(qbl("utf-8")));
    varStream.setGenerateByteOrderMark(true);

    /*输出头文件信息*/
    outputHeader(varStream);

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
]{geometry}               %导入包geometry

)__1__");


}

extern void output_main_index() try {

    output_setup_page_geometry_a4();

    QFile varFile{ getOutPutFileFullPath( qsl("main_index.tex") ) };
    if( varFile.open( QIODevice::WriteOnly ) == false ){
        the_book_throw("can not open file main_index.tex"sv);
    }

    QTextStream varStream{ &varFile };
    varStream.setCodec( QTextCodec::codecForName(qbl("utf-8")) );
    varStream.setGenerateByteOrderMark(true);

    /*输出头文件信息*/
    outputHeader(varStream);

    varStream << qsl(R"___1_(

\documentclass[hyperref,UTF8]{ctexbook}
\input{setup_page_geometry_a4}%设置纸张大小，页边距

\begin{document}



\end{document}


)___1_");

} catch( ... ) {
    throw;
}





