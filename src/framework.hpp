#pragma once
// STL
#include <functional>   // std::function
#include <iostream>     // std::cout, std::endl
#include <map>          // std::map
#include <memory>       // std::unique_ptr
#include <string>       // std::string
#include <sstream>      // std::stringstream
#include <string_view>  // std::string_view
#include <variant>      // std::variant
#include <vector>       // std::vector

// WinAPI
#include <windows.h>

// Local Dependencies
#include "deps/argparse.hpp"

// Local
#include "compile/compile.hpp"
#include "jdktools/jdk.hpp"
#include "util/util.hpp"
#include "settings/settings.hpp"
