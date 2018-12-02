CONFIG(debug,debug|release){#debug

    RootDestDir = $$PWD/bin/final
    TestRootDestDir = $$PWD/bin/test
    DEFINES *= _DEBUG

}else{#release

    RootDestDir = $$PWD/bin/final
    TestRootDestDir = $$PWD/bin/test
    DEFINES *= NDEBUG #assert
    DEFINES *= QT_NO_DEBUG #Q_ASSERT,Q_ASSERT_X

}




















