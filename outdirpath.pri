win32-msvc*{

    TestRootDestDir = $$PWD/bin/msvc_test
    RootDestDir = $$PWD/bin/msvc_final

}else{

    TestRootDestDir = $$PWD/bin/test
    RootDestDir = $$PWD/bin/final

}

CONFIG(debug,debug|release){#debug

    DEFINES *= _DEBUG

}else{#release

    DEFINES *= NDEBUG #assert
    DEFINES *= QT_NO_DEBUG #Q_ASSERT,Q_ASSERT_X

}




















