#pragma once
#include "../framework.hpp"

struct settings_t {
	// link to x86 jdk
	char* remoteJdkX86{};
	// link to x64 jdk
	char* remoteJdkX64{};
	// remote git repository
	char* repository{};
	// option to skip check for jdk
	bool skipJdkCheck{};
	// option to force update
	bool forceUpdate{};
	// option to force compilation
	bool forceCompilation{};
}; inline settings_t settings;

namespace args {
	void setup(int argc, char** argv);
}