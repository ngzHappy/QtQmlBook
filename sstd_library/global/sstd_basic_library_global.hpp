#pragma once

#if defined(__cplusplus)/*__cplusplus*/
#include <cmath>
#include <limits>
#include <utility>
#include <type_traits>
#endif/*__cplusplus*/

#include <boost/config.hpp>

/*just support dynamic library*/
#if defined(_1_SSTD_CORE_LIBRARY) /*_1_SSTD_CORE_LIBRARY*/
#define _1_SSTD_CORE_EXPORT BOOST_SYMBOL_EXPORT
#else
#define _1_SSTD_CORE_EXPORT BOOST_SYMBOL_IMPORT
#endif/*_1_SSTD_CORE_LIBRARY*/

#ifndef sstdg
#define sstdg
#endif

#if defined(_1_SSTD_CORE_LIBRARY) && defined( _MSC_VER )
#pragma warning(disable:4251)
#endif















