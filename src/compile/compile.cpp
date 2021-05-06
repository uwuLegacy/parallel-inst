#include "compile.hpp"

bool compile::compile() {
	if (settings.forceCompilation) {
		std::cout << "[+] force compilation flag on\n";
		std::cout << "[+] starting compilation\n";
		RemoveDirectoryA(".\\build");
		std::system(".\\gradlew.bat RatPoison");
	}
	else if (!util::DirectoryExists(".\\build")) {
		std::cout << "[+] starting compilation\n";
		std::system(".\\gradlew.bat RatPoison");
	}
	else {
		if (util::Prompt("[?] build already exists, rebuild?")) {
			RemoveDirectoryA(".\\build");
			std::system(".\\gradlew.bat RatPoison");
		}
		else {
			std::cout << "[=] stopping compilation\n";
		}
	}
	return true;
}