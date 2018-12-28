#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <type_traits>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>

using char_type = char;

/*所有合法关键字集合*/
constexpr const static std::array<char_type, 26 + 10>
all_key_words_set{
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z',
    '0','1','2','3','4','5','6','7','8','9',
};

/*密码长度*/
constexpr const static std::size_t key_length = 4;

/*key type*/
using key_type = std::array< char_type, key_length  >;

/*求阶乘*/
template<std::size_t N>
inline constexpr std::size_t factorial() {
    if constexpr (N < 2) {
        return 1;
    } else {
        return N * factorial<N - 1>();
    }
}

/*获得一个组合数,可以重复*/
class KeyNumber {
    constexpr const static std::size_t min_number = 0;
    constexpr const static std::size_t max_number = all_key_words_set.size() - 1;
    std::array< std::size_t, key_length > data;
public:

    inline KeyNumber() {
        for (auto & varI : data) {
            varI = min_number;
        }
    }

    inline bool next() {
        for (auto & varI : data) {
            if (varI == max_number) {
                varI = min_number;
                continue;
            } else {
                ++varI;
                return true;
            }
        }
        return false;
    }

    template<std::size_t N = key_length >
    inline constexpr static std::size_t total_size() {
        if constexpr (N < 2) {
            return all_key_words_set.size();
        } else {
            return total_size<1>() * total_size<N - 1>();
        }
    }

    inline key_type getCurrentKey() const {
        return {
            all_key_words_set[data[0]],
            all_key_words_set[data[1]],
            all_key_words_set[data[2]],
            all_key_words_set[data[3]]
        };
    }

};

template<typename S, typename T>
inline void out_put(S && s, T && t) {
    for (const auto & varI : t) {
        std::forward<S>(s) << varI;
    }
    std::forward<S>(s)
        << std::endl;
}

inline std::size_t number_weight(const key_type & arg) {
    std::size_t varAns = 0;
    for (const auto & varI : arg) {
        if ((varI <= '9') && (varI >= '0')) {
            ++varAns;
        }
    }
    switch (varAns) {
    case 0:return 2;
    case 1:return 0;
    case 2:return 1;
    case 3:return 3;
    case 4:return 4;
    }
    return varAns;
}

inline bool compare_a_key(const key_type & l, const key_type & r) {

    const auto leftNumberWeight = number_weight(l);
    const auto rightNumberWeight = number_weight(r);

    return (leftNumberWeight < rightNumberWeight);

}

inline static std::string number_to_string(int arg) {
    std::stringstream varStream;
    varStream << std::setw(8) << std::setfill('0') << arg;
    std::string varAns;
    varStream >> varAns;
    return std::move(varAns);
}

int main(int argc, char ** argv) {

    KeyNumber varKeyGet;

    std::vector< key_type > varAllKeys;
    varAllKeys.reserve(varKeyGet.total_size());

    do {
        varAllKeys.push_back(varKeyGet.getCurrentKey());
    } while (varKeyGet.next());

    std::shuffle(varAllKeys.begin(), varAllKeys.end(), std::mt19937{});
    std::sort(varAllKeys.begin(), varAllKeys.end(), compare_a_key);

    auto varPos = varAllKeys.cbegin();
    const auto varEnd = varAllKeys.cend();
    int varFileIndex = 0;
    while (varPos != varEnd) {
        std::string varFileName{ number_to_string(varFileIndex++) };
        std::ofstream varStream(varFileName + "keys.txt", std::ios::binary);
        for (int varFileIndex1 = 0; varFileIndex1 < 10'000; ++varFileIndex1) {
            if (varPos != varEnd) {
                const auto & varAKey = *varPos;
                out_put(varStream, varAKey);
                ++varPos;
            } else {
                break;
            }
        }
    }

}
