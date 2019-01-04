#include "sstd_copy_dir.hpp"
#include <QtCore/QtCore>
#include <iostream>
#include <fstream>

#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#define EXPERIMENTAL_FILESYSTEM (1u)
#endif

namespace _this_file_private {

#if __has_include(<execution>)
    //#include <execution>
#define NO_STD_EXCUTION (1u)
#else
#define NO_STD_EXCUTION (1u)
#endif

    using namespace std::string_view_literals;

    /*************************************************/
    /*一个拷贝文件的任务*/
    class DutyItem {
    public:
        fs::path copyDir;
        DutyItem(fs::path && a) :copyDir(std::move(a)) {
        }
        DutyItem(const fs::path & a) :copyDir(a) {
        }
        DutyItem(const DutyItem &) = default;
        DutyItem(DutyItem &&) = default;
        DutyItem&operator=(const DutyItem &) = default;
        DutyItem&operator=(DutyItem &&) = default;
    private:
        SSTD_DEFINE_STATIC_CLASS(DutyItem);
    };

    /*************************************************/
    class Duty {
    public:
        fs::path toDir;
        fs::path fromDir;
        inline bool copy();
    private:
        class CopyInformation {
        public:
            sstd::list<fs::path> dirs;
            sstd::list<fs::path> files;
        };
        inline bool _p_copy_files(const CopyInformation &) const;
        inline bool _p_create_dirs(const CopyInformation &) const;
        inline static bool _p_copy_a_file(const fs::path &, const fs::path &);
        inline static bool __p_copy_a_file(const fs::path &, const fs::path &);
        inline static CopyInformation _p_get_dir_copy_information(const fs::path &);
    private:
        SSTD_DEFINE_STATIC_CLASS(Duty);
    };

    bool copy_main(const fs::path & argFromDir, const fs::path & varToDir) try {
        auto duty = sstd_make_unique<Duty>();
        duty->toDir = varToDir;
        duty->fromDir = argFromDir;
        return duty->copy();
    } catch (const std::exception & arg) {
        sstd_log(arg.what());
        return false;
    }

    inline bool Duty::copy() {
        const auto varCI = _p_get_dir_copy_information(
            this->fromDir);
        if (false == _p_create_dirs(varCI)) {
            return false;
        }
        if (false == _p_copy_files(varCI)) {
            return false;
        }

        return true;
    }

    /*创建目录*/
    inline bool Duty::_p_create_dirs(const CopyInformation & items) const {
        for (const auto & i : items.dirs) {
            bool isNeedCreate = true;
            try {
                const auto varPath = toDir / i;
                do {
                    const auto varStatus = status(varPath);
                    if (!exists(varStatus)) {
                        break;
                    }
                    if (!is_directory(varStatus)) {
                        remove(varPath);
                        break;
                    } else {
                        const auto varRPath = canonical(varPath);
                        if (varRPath.filename() != varPath.filename()) {
                            rename(varRPath, varPath);
                        }
                        isNeedCreate = false;
                    }
                } while (false);
                if (isNeedCreate) {
                    create_directories(varPath);
                }
            } catch (...) {
                return false;
            }
        }
        return true;
    }

    using path_t = fs::path;
    inline Duty::CopyInformation Duty::_p_get_dir_copy_information(
        const fs::path & root) try {
        class FileItem {
        public:
            path_t path;
            FileItem(path_t && a) :path(std::move(a)) {
            }
            FileItem(const path_t & a) :path(a) {
            }
            FileItem(const FileItem &) = default;
            FileItem(FileItem&&) = default;
            FileItem&operator=(const FileItem &) = default;
            FileItem&operator=(FileItem &&) = default;
        };

        sstd::list<FileItem> items;
        items.emplace_back(root);
        Duty::CopyInformation ans;

        /*获得相对路径，鉴于某些版本的filesystem没有这个功能*/
        auto getRelative = [](const fs::path & arg, std::size_t n)->fs::path {
            ++n;
            sstd::list<decltype(arg.begin())> var;
            {
                auto varI = arg.begin();
                auto varE = arg.end();
                for (; varI != varE; ++varI) {
                    var.push_back(varI);
                }
            }
            while (var.size() > n) {
                var.pop_front();
            }
            if (var.empty()) {
                return{};
            }
            fs::path varAns = *(var.front());
            var.pop_front();
            while (false == var.empty()) {
                varAns /= *(var.front());
                var.pop_front();
            }
            return std::move(varAns);
        };

        while (false == items.empty()) {
            FileItem item = items.front();
            items.pop_front();
            fs::recursive_directory_iterator varRDI(item.path);
            fs::recursive_directory_iterator varEnd;
            for (; varRDI != varEnd; ++varRDI) {
                assert(varRDI.depth() >= 0);
                const auto varDeepth =
                    static_cast<std::size_t>(varRDI.depth());
                const auto & varI = *varRDI;
                if (is_directory(varI.status())) {
                    ans.dirs.push_back(getRelative(
                        fs::canonical(varI.path()), varDeepth));
                } else {
                    ans.files.push_back(getRelative(
                        fs::canonical(varI.path()), varDeepth));
                }
            }
        }

        return std::move(ans);
    } catch (...) {
        return{};
    }

    inline bool Duty::_p_copy_files(const CopyInformation & items) const {
        sstd::list< std::pair<fs::path, fs::path> > calls;
        for (const auto & i : items.files) {
            calls.emplace_back(fromDir / i, toDir / i);
        }
        for (const auto & a : calls) {
            if (false == _p_copy_a_file(a.first, a.second)) {
                return false;
            }
        }
        return true;
    }

    inline bool Duty::_p_copy_a_file(
        const fs::path & a,
        const fs::path & b) {
        return __p_copy_a_file(a, b);
    }

    /*copy file*/
    inline bool Duty::__p_copy_a_file(
        const fs::path & a,
        const fs::path & b) try {

        const auto varBStates = status(b);
        if (exists(varBStates)) {

            /*如果目标当前是目录，删除目录，拷贝文件*/
            if (is_directory(varBStates)) {
                remove_all(b);
                fs::copy(a, b);
                return true;
            }

            {
                /*
                there may be a bug @ case-sensitive
                so we force rename the file
                */
                auto varPathB = canonical(b);
                if (varPathB.filename() != b.filename()) {
                    rename(varPathB, b);
                }
            }

            {/*不相信时间戳，直接比较内容...*/
                if (fs::file_size(b) == fs::file_size(a)) {

#if defined(EXPERIMENTAL_FILESYSTEM)
                    std::ifstream varFrom(a.string(), std::ios::binary);
                    std::ifstream varTo(b.string(), std::ios::binary);
#else
                    std::ifstream varFrom{ a,std::ios::binary };
                    std::ifstream varTo{ b,std::ios::binary };
#endif
                    constexpr const static int Size = 1024;
                    alignas(void *) char blockA[Size];
                    alignas(void *) char blockB[Size];

                    do {
                        varFrom.read(blockA, Size);
                        varTo.read(blockB, Size);

                        const auto varNext0 = varFrom.gcount();
                        const auto varNext1 = varTo.gcount();

                        if (varNext0 != varNext1) {
                            break;
                        }

                        if (varNext0 < 1) {
                            /*the file is same*/
                            return true;
                        }

                        if (::memcmp(blockA, blockB, varNext0) != 0) {
                            break;
                        }

                    } while (true);
                }
            }

            fs::copy_file(a, b, fs::copy_options::overwrite_existing);

    } else {
            fs::copy(a, b);
        }

        return true;
} catch (...) {
    return false;
}

        }/**/


namespace sstd {

    EXPORT_SSTD_QT_AND_QML_LIBRARY bool copyDir(
        const QString & argFrom,
        const QString & argTo) {

        QFileInfo varFromInfo{ argFrom };
        QFileInfo varToInfo{ argTo };

        const auto varFromPathLocal =
            varFromInfo.absoluteFilePath().toLocal8Bit();

        const auto varToPathLocal =
            varToInfo.absoluteFilePath().toLocal8Bit();

        const fs::path varFrom{
            varFromPathLocal.constData() };
        const fs::path varTo{
            varToPathLocal.constData() };

        return
            _this_file_private::copy_main(varFrom, varTo);

    }

}/*namespace sstd*/









