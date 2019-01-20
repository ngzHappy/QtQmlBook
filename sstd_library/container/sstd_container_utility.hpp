#pragma once

#include <utility>
#include <iterator>
#include <type_traits>

namespace sstd::_12_private{
     template<typename T,typename U,typename = void
    > class CanEqual : public std::false_type {
    };
    template<typename T,typename U
    > class CanEqual<T,U,std::void_t<
        decltype(std::declval<T&&>() == std::declval<U&&>())>
    > : public std::true_type {
    };   
}/*sstd::_12_private*/

namespace sstd{

/*move list frist to last ...*/
template<typename T>
inline void move_list_front_to_back(T & arg) {
    const auto varListSize = arg.size();
    if(varListSize > 2) {
        arg.splice(arg.end(),arg,arg.cbegin());
        return;
    }
    if(varListSize < 2) {
        /*if empty or just one element do nothing*/
        return;
    }
    arg.reverse();
    return;
}

}/*sstd*/

namespace sstd{

/*move list last to first ...*/
template<typename T>
inline void move_list_back_to_front(T & arg) {
    const auto varListSize = arg.size();
    if(varListSize > 2) {
        arg.splice(arg.begin(),arg,--arg.cend());
        return;
    }
    if(varListSize < 2) {
        /*if empty or just one element do nothing*/
        return;
    }
    arg.reverse();
    return;
}

}/*sstd*/

namespace sstd{
    
/*move list element to last ...*/
template<typename T,typename I>
inline void move_list_element_to_back(T & arg,const I & pos) {
    using ele_pos_type = decltype(arg.cbegin());
    constexpr bool const canEqual =
        _12_private::CanEqual<ele_pos_type,I>::value;
    if constexpr(canEqual) {
        if((arg.cend() != pos)&&(pos != (--arg.cend()))) {
            arg.splice(arg.end(),arg,pos);
        }
    } else {
        if(arg.crend() != pos) {
            return move_list_element_to_back(arg,--pos.base());
        }
    }
}

}/*sstd*/

namespace sstd{

/*move list element to front ...*/
template<typename T,typename I>
inline void move_list_element_to_front(T & arg,const I & pos) {
    using ele_pos_type = decltype(arg.cbegin());
    constexpr bool const canEqual =
        _12_private::CanEqual<ele_pos_type,I>::value;
    if constexpr(canEqual) {
        if((arg.cbegin() != pos)&&(arg.cend() != pos)) {
            arg.splice(arg.begin(),arg,pos);
        }        
    } else {
        if(arg.crend() != pos) {
            return move_list_element_to_front(arg,--pos.base());
        }
    }
}

}/*sstd*/







