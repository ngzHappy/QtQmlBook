#include "sstd_glew_initialization.hpp"

#include "GLSSTD/glew.h"
#include <sstd_library.hpp>
#include <string_view>
#include <mutex>

using namespace std::string_view_literals;

inline static bool _0_sstd_init_glew(){

    glewExperimental = GL_TRUE;
    auto varGlewError = glewInit() ;
    if (varGlewError != GLEW_OK) {
        sstd_error("glew init error!"sv);
        return false;
    }

    return true;

}

inline static bool _call_once_init_glew(){
    static std::once_flag varCallOnce;
    static bool varAns{true};
    std::call_once(varCallOnce ,[](bool * ans){
        *ans = _0_sstd_init_glew() ;
    } , &varAns );
    return varAns;
}

EXPORT_SSTD_QT_AND_QML_LIBRARY bool sstd::glew_initialize(){
    return _call_once_init_glew();
}


















