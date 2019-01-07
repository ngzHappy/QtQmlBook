#import_library.pro
TEMPLATE = subdirs

CONFIG += ordered

test_library.file = $$PWD/test_library/test_library.pro
SUBDIRS += test_library

the_app.file = $$PWD/the_app/the_app.pro
SUBDIRS += the_app




































