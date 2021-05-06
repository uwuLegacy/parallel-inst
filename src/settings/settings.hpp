#pragma once
#include "../framework.hpp"

struct settings_t {
	// link to x86 jdk
	const char* remoteJdkX64{ "https://download.java.net/java/GA/jdk14.0.2/205943a0976c4ed48cb16f1043c5c647/12/GPL/openjdk-14.0.2_windows-x64_bin.zip" };
	// link to x64 jdk
	const char* remoteJdkX86{ "https://github.com/AdoptOpenJDK/openjdk14-binaries/releases/download/jdk-14.0.2%2B12/OpenJDK14U-jdk_x86-32_windows_hotspot_14.0.2_12.zip" };
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