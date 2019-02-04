#pragma once

#include "the_book_global.hpp"

class CreateMakeFileConstruct {
public:
    virtual ~CreateMakeFileConstruct() = default;
    QString rootFileName;
    inline CreateMakeFileConstruct(
        const QString & argRootFileName = QStringLiteral("main_index.txt")
    ) : rootFileName(argRootFileName) {
    }
};

class CreateMakeFilePrivate;

class CreateMakeFile {
public:
    CreateMakeFile(std::shared_ptr<const CreateMakeFileConstruct> arg
        = std::make_shared<CreateMakeFileConstruct>() );
    bool createMakeFile();
private:
    std::shared_ptr<CreateMakeFilePrivate> thisp;
};
