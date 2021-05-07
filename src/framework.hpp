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
#include <fstream>      // std::ofstream
#include <iomanip>      // std::setw

// WinAPI
#include <windows.h>
#include <WinInet.h>
#include <urlmon.h>

// Linked Libraries
#pragma comment(lib, "urlmon.lib")

// Local Dependencies
#include "deps/argparse.hpp"

// Local
#include "compile/compile.hpp"
#include "remote/jdktools/jdk.hpp"
#include "util/util.hpp"
#include "settings/settings.hpp"
#include "util/dl/dl.hpp"
#include "remote/repo/repo.hpp"