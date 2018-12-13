#include "sstd_get_local_file_full_path.hpp"

namespace sstd {

    EXPORT_SSTD_QT_AND_QML_LIBRARY QUrl getLocalFileFullPath(
        const QString & argFileName,
        const QString & argBase) {

        const auto varAns = getLocalFileFullFilePath(argFileName, argBase);
        if (varAns.startsWith(QChar('/'))) {
            return QStringLiteral(R"(file://)") + varAns;
        } else {
            return QStringLiteral(R"(file:///)") + varAns;
        }

    }

    EXPORT_SSTD_QT_AND_QML_LIBRARY QString getLocalFileFullFilePath(
        const QString & argFileName,
        const QString & argBase) {

        const QDir varRootDir{ argBase };
        return varRootDir.absoluteFilePath(argFileName);

    }

    EXPORT_SSTD_QT_AND_QML_LIBRARY sstd::string getLocalFileFullFilePath(
        std::string_view varName,
        std::string_view varDir) {

        if (varName.empty()) {
            return sstd::string{ varDir };
        }

        if (varDir.empty()) {
            return sstd::string{ varName };
        }

        bool varNameOp;
        bool varDirOp;

        varNameOp = ((varName[0] == '/') || (varName[0] == '\\'));
        {
            auto varChar = *varDir.rbegin();
            varDirOp = ((varChar == '/') || (varChar == '\\'));
        }

        if (varDirOp&&varNameOp) {
            sstd::string varAns;
            varAns.reserve(varName.size() + varDir.size());
            varAns += varDir;
            varAns.resize(varDir.size() - 1);
            varAns += varName;
            return std::move(varAns);
        }

        sstd::string varAns;
        varAns.reserve(varName.size() + varDir.size() + 1);
        varAns += varDir;
        if ((varDirOp == false) && (false == varNameOp)) {
            varAns += '/';
        }
        varAns += varName;
        return std::move(varAns);

    }

}









