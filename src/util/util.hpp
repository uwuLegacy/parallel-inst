#pragma once
#include "../framework.hpp"
// Win32 internet libs
#include <WinInet.h>
#pragma comment(lib, "Wininet.lib")

namespace util {
	bool TestConnection();
	void ShowHelp();
	bool createGradle();
	bool DirectoryExists(const char* szPath);
	bool Prompt(const char* szPrompt);
	std::string execute(const char* cmd);
}
