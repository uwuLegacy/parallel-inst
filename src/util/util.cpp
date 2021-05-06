#include "util.hpp"

bool util::TestConnection() {
	if (!InternetCheckConnectionA("http://github.com", FLAG_ICC_FORCE_CONNECTION, 0)) {
		std::cout << "[-] Connection unavailable, are you connected to the Internet?\n";
		return false;
	}
	else {
		std::cout << "[+] Connection check successful.\n";
	}
}

void util::ShowHelp() {
	std::cout << "      [ RatPoison Installer Help ]\n"
		<< "--skipJdkCheck (-s) - Skips checking for installed JDK\n"
		<< "--forceUpdate (-U) - Forces cheat update from remote repo\n"
		<< "--forceCompile (-C) - Forces cheat recompilation\n"
		<< std::endl;
}