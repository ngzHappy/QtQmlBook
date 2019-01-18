#pragma once

#include <sstd_library.hpp>
#include <future>
#include <exception>
#include <boost/context/fiber.hpp>
#include <boost/context/protected_fixedsize_stack.hpp>

namespace sstd {

    using Fiber = boost::context::fiber;

}/*namespace sstd*/

 




