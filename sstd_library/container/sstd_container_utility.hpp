#pragma once

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
    
/*move list element to last ...*/
template<typename T,typename I>
inline void move_list_element_to_back(T & arg,const I & pos) {
    if(arg.cend() == pos) {
        return;
    }
    if(pos == (--arg.cend())) {
        return;
    }
    arg.splice(arg.end(),arg,pos);
    return;
}

}/*sstd*/

namespace sstd{

/*move list element to front ...*/
template<typename T,typename I>
inline void move_list_element_to_front(T & arg,const I & pos) {
    if(arg.cbegin() == pos) {
        return;
    }
    if(arg.cend() == pos) {
        return;
    }
    arg.splice(arg.begin(),arg,pos);
    return;
}

}/*sstd*/







