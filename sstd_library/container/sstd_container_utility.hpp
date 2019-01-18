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













