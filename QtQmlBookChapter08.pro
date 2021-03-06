##############08##############

TEMPLATE = subdirs

app_firstcanvas.file = $$PWD/chapter08/firstcanvas/firstcanvas.pro
SUBDIRS += app_firstcanvas

app_firstchart.file = $$PWD/chapter08/firstchart/firstchart.pro
SUBDIRS += app_firstchart

app_charts.file = $$PWD/chapter08/charts/charts.pro
SUBDIRS += app_charts

app_texteditdeep.file = $$PWD/chapter08/texteditdeep/texteditdeep.pro
SUBDIRS += app_texteditdeep

app_texteditwithgif.file = $$PWD/chapter08/texteditwithgif/texteditwithgif.pro
SUBDIRS += app_texteditwithgif

lib_chatview_basic.file = $$PWD/chapter08/chatview/chatview_basic/chatview_basic.pro
lib_chatview_left.file = $$PWD/chapter08/chatview/chatview_left/chatview_left.pro
lib_chatview_right.file = $$PWD/chapter08/chatview/chatview_right/chatview_right.pro
app_chatview.file = $$PWD/chapter08/chatview/chatview.pro
lib_chatview_left.depends = lib_chatview_basic
lib_chatview_right.depends = lib_chatview_basic
app_chatview.depends = lib_chatview_basic lib_chatview_left lib_chatview_right
SUBDIRS += lib_chatview_basic
SUBDIRS += lib_chatview_left
SUBDIRS += lib_chatview_right
SUBDIRS += app_chatview
