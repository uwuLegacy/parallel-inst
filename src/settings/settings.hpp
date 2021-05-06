#pragma once
#include "../framework.hpp"

struct CSettings {
	// link to x86 jdk
	char* remoteJdkX86{};
	// link to x64 jdk
	char* remoteJdkX64{};
	// remote git repository
	char* repository{};
	// option to skip check for jdk
	bool skipJdkCheck{};
	// option to force update
	bool forceCheatUpdate{};
	// option to force compilation
	bool forceCompilation{};
};