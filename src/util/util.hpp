#pragma once
#include "../framework.hpp"
// Win32 internet libs
#include <WinInet.h>
#pragma comment(lib, "Wininet.lib")

namespace util {
	bool TestConnection();
	void ShowHelp();
	bool createGradle();
}
