#include <static_boost/filesystem.hpp>
#include <static_boost/filesystem/fstream.hpp>

#include <list>
#include <regex>
#include <memory>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <utility>
#include <iostream>

#if __has_include(<execution>)
//#include <execution>
#define NO_STD_EXCUTION (1u)
#else
#define NO_STD_EXCUTION (1u)
#endif

#include <algorithm>
#include <functional>
#include <string_view>

using namespace std::string_view_literals;

/*************************************************/
class DutyItem {
public:
    boost::filesystem::path copyDir;
    DutyItem(boost::filesystem::path && a) :copyDir(std::move(a)) {
    }
    DutyItem(const boost::filesystem::path & a) :copyDir(a) {
    }
    DutyItem(const DutyItem &) = default;
    DutyItem(DutyItem &&) = default;
    DutyItem&operator=(const DutyItem &) = default;
    DutyItem&operator=(DutyItem &&) = default;
};

/*************************************************/
class Duty {
public:
    boost::filesystem::path toDir;
    boost::filesystem::path fromDir;
    std::list<DutyItem> items;
    inline void copy() const;
private:
    class CopyInformation {
    public:
        std::list<boost::filesystem::path> dirs;
        std::list<boost::filesystem::path> files;
    };
    inline void _p_copy_files(const CopyInformation &) const;
    inline void _p_create_dirs(const CopyInformation &) const;
    inline static void _p_copy_a_file(const boost::filesystem::path &, const boost::filesystem::path &);
    inline static void __p_copy_a_file(const boost::filesystem::path &, const boost::filesystem::path &);
    inline static CopyInformation _p_get_dir_copy_information(const boost::filesystem::path &, const boost::filesystem::path &);
};

//#define INSTALL_LOG_DEBUG 1
#if defined(_DEBUG)
#define PASS_DEBUG 0
#endif

int main(int argc, char ** argv) try {

#if PASS_DEBUG
    /*在debug模式下跳过动作*/
    return 0;
#endif

    const auto varToDir = boost::filesystem::path(/*u8*/ToDir);
#ifdef INSTALL_LOG_DEBUG
    std::ofstream varLogStream{ varToDir / u8R"(install.log)",std::ios::binary };
#endif
    Duty duty;

    if (argc < 3) {
#ifdef INSTALL_LOG_DEBUG
        varLogStream << "do not input root dir:copy dir" << std::endl;
#endif
        return 0;
    } else {
#ifdef INSTALL_LOG_DEBUG
        varLogStream << "copy dir:" << std::endl;
#endif
        duty.toDir = varToDir;
        duty.fromDir = boost::filesystem::path(/*u8*/argv[1]);
        for (int i = 2; i < argc; ++i) {
            const auto & varI = duty.items.emplace_back(boost::filesystem::path(/*u8*/argv[i]));
#ifdef INSTALL_LOG_DEBUG
            varLogStream << varI.copyDir << std::endl;
#else
            (void)varI;
#endif
        }
#ifdef INSTALL_LOG_DEBUG
        varLogStream << std::endl;
#endif
    }

    duty.copy();

    return 0;

} catch (...) {
    return 0;
}


inline void Duty::copy() const {
    for (const auto & varItem : items) {
        const auto varCI = _p_get_dir_copy_information(
            this->fromDir,
            this->fromDir / varItem.copyDir);
        _p_create_dirs(varCI);
        _p_copy_files(varCI);
    }
}

/*创建目录*/
inline void  Duty::_p_create_dirs(const CopyInformation & items) const {
    for (const auto & i : items.dirs) {
        try {
            const auto varPath = toDir / i;
            do {
                const auto varStatus = boost::filesystem::status(varPath);
                if (!boost::filesystem::exists(varStatus)) {
                    break;
                }
                if (!boost::filesystem::is_directory(varStatus)) {
                    boost::filesystem::remove(varPath);
                    break;
                } else {
                    const auto varRPath = boost::filesystem::canonical(varPath);
                    if (varRPath.filename() != varPath.filename()) {
                        boost::filesystem::rename(varRPath, varPath);
                        return;
                    }
                }
            } while (false);
            boost::filesystem::create_directories(varPath);
        } catch (...) {
        }
    }
}

inline Duty::CopyInformation Duty::_p_get_dir_copy_information(
    const boost::filesystem::path & root,
    const boost::filesystem::path & arg) try {
    class FileItem {
    public:
        boost::filesystem::path path;
        FileItem(boost::filesystem::path && a) :path(std::move(a)) {
        }
        FileItem(const boost::filesystem::path & a) :path(a) {
        }
        FileItem(const FileItem &) = default;
        FileItem(FileItem&&) = default;
        FileItem&operator=(const FileItem &) = default;
        FileItem&operator=(FileItem &&) = default;
    };

    std::list<FileItem> items;
    items.emplace_back(arg);
    Duty::CopyInformation ans;
    ans.dirs.push_back(boost::filesystem::relative(arg, root));

    while (false == items.empty()) {
        FileItem item = items.front();
        items.pop_front();
        boost::filesystem::recursive_directory_iterator varRDI(item.path);
        for (const auto & varI : varRDI) {
            if (boost::filesystem::is_directory(varI.status())) {
                const auto & varPath = items.emplace_back(varI.path());
                ans.dirs.push_back(boost::filesystem::relative(varPath.path, root));
            } else {
                ans.files.push_back(boost::filesystem::relative(varI.path(), root));
            }
        }
    }

    return std::move(ans);
} catch (...) {
    return{};
}

inline void Duty::_p_copy_files(const CopyInformation & items) const {
    std::list< std::pair<boost::filesystem::path, boost::filesystem::path> > calls;
    for (const auto & i : items.files) {
        calls.emplace_back(fromDir / i, toDir / i);
    }
    std::for_each(
#if defined(NO_STD_EXCUTION)
        /*...*/
#else
#if defined(_DEBUG)
        std::execution::seq,
#else
        std::execution::par_unseq,
#endif
#endif
        calls.cbegin(), calls.cend(),
        [](const auto & a) { _p_copy_a_file(a.first, a.second); });
}

#if defined(_DEBUG)

#else
//pure
/*begin:debug*/
/*end:debug*/
inline void __parser_qml(const boost::filesystem::path & b) try {

    enum {
        normal_line = 0,
        begin_type = 1,
        end_type = 2,
    };

    class Line : public std::string {
    public:
        std::size_t type = normal_line;
    };

    std::vector<Line> varLines;

    const static std::regex varRegexDebugBegin{ "(?:" "\xef" "\xbb" "\xbf" ")?" "\\s*/\\*begin:debug\\*/\\s*" , std::regex::icase };
    const static std::regex varRegexDebugEnd{ u8R"(\s*/\*end:debug\*/\s*)", std::regex::icase };
    bool hasDebugData = false;
    {
        boost::filesystem::ifstream varReadStream{ b,std::ios::binary };
        if (false == varReadStream.is_open()) {
            return;
        }

        while (varReadStream.good()) {
            Line varLine;
            std::getline(varReadStream, varLine);
            if (varLine.empty() == false) {
                if (std::regex_match(varLine, varRegexDebugBegin)) {
                    varLine.type = begin_type;
                    hasDebugData = true;
                } else if (std::regex_match(varLine, varRegexDebugEnd)) {
                    varLine.type = end_type;
                    hasDebugData = true;
                }
            }
            varLines.push_back(std::move(varLine));
        }

    }

    if (varLines.empty()) {
        return;
    }

    if (false == hasDebugData) {
        return;
    }

    boost::filesystem::ofstream varOutStream{ b,std::ios::binary };
    if (false == varOutStream.is_open()) {
        return;
    }

    int varDebugCount = 0;
    for (const auto & varLine : varLines) {

        const auto varOldDebugCount = varDebugCount;
        if (varLine.type == begin_type) {
            ++varDebugCount;
        } else if (varLine.type == end_type) {
            --varDebugCount;
        }

        if ((0 < varDebugCount) || (0 < varOldDebugCount)) {
            varOutStream << u8"/*remove debug information*/"sv << std::endl;
        } else {
            varOutStream << varLine << std::endl;
        }

    }

} catch (...) {
}
#endif

inline void Duty::_p_copy_a_file(const boost::filesystem::path & a, const boost::filesystem::path & b) {
    __p_copy_a_file(a, b);
    /*****************************************/
    /*release qml ... */
    try {
        bool varIsQml;
        {
            const static std::regex varRegex{ "\\.qml", std::regex::icase };
            const auto varExtension = b.extension().string();
            varIsQml = std::regex_match(varExtension, varRegex);
        }
        if (false == varIsQml) {
            return;
        }

#if defined(_DEBUG)
#else
        __parser_qml(b);
#endif

    } catch (...) {
        return;
    }
    /*****************************************/
}

/*copy file*/
inline void Duty::__p_copy_a_file(const boost::filesystem::path & a, const boost::filesystem::path & b) try {
    const auto varBStates = boost::filesystem::status(b);
    if (boost::filesystem::exists(varBStates)) {

        /*如果目标当前是目录，删除目录，拷贝文件*/
        if (boost::filesystem::is_directory(varBStates)) {
            boost::filesystem::remove_all(b);
            boost::filesystem::copy(a, b);
            return;
        }

        {
            /*
            there may be a bug @ case-sensitive
            so we force rename the file
            */
            auto varPathB = boost::filesystem::canonical(b);
            if (varPathB.filename() != b.filename()) {
                boost::filesystem::rename(varPathB, b);
            }
        }

        boost::filesystem::ifstream varFrom{ a,std::ios::binary };
        boost::filesystem::ifstream varTo{ b,std::ios::binary };

        if (boost::filesystem::file_size(b) == boost::filesystem::file_size(a)) {

            constexpr const static int Size = 1024;
            alignas(void *) char blockA[Size];
            alignas(void *) char blockB[Size];

            boost::filesystem::ifstream varFrom(a, std::ios::binary);
            boost::filesystem::ifstream varTo(b, std::ios::binary);

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
                    return;
                }

                if (std::memcmp(blockA, blockB, varNext0) != 0) {
                    break;
                }

            } while (true);
        }

        boost::filesystem::copy_file(a, b, boost::filesystem::copy_option::overwrite_if_exists);

    } else {
        boost::filesystem::copy(a, b);
    }
} catch (...) {
    return;
}










