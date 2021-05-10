#include "util.hpp"

bool util::TestConnection() {
	if (!InternetCheckConnectionA("http://github.com", FLAG_ICC_FORCE_CONNECTION, 0)) {
		std::cout << "[-] Connection unavailable, are you connected to the Internet?\n";
		return false;
	}
	else {
		std::cout << "[+] Connection check successful.\n";
		return true;
	}
}

void util::ShowHelp() {
	std::cout << "      [ RatPoison Installer Help ]\n"
		<< "--skipJdkCheck (-s) - Skips checking for installed JDK\n"
		<< "--forceUpdate (-U) - Forces cheat update from remote repo\n"
		<< "--forceCompile (-C) - Forces cheat recompilation\n"
		<< std::endl;
}

bool util::createGradle() {
	HRESULT hRes = URLDownloadToFileA(
		FALSE,
		"https://raw.githubusercontent.com/RatPoison-dev/RatPoison/master/gradlew.bat",
		".\\RatPoison\\gradlew.bat",
		0,
		NULL
	);
	if (SUCCEEDED(hRes)) {
		std::cout << "[+] gradle wrapper downloaded\n";
	}
	else {
		std::cout << "[-] failed to download gradle wrapper\n";
	}
}

bool util::DirectoryExists(const char* szPath) {
	DWORD dwAttrib = GetFileAttributesA(szPath);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

bool util::Prompt(const char* szPrompt) {
	while (true) {
		std::cout << szPrompt << " [y/n] ";
		std::string line;
		if (!std::getline(std::cin, line)) {
			throw std::runtime_error("unexpected input error");
		}
		else if (line.size() == 1 and line.find_first_of("YyNn") != line.npos) {
			return line == "Y" || line == "y";
		}
	}
}

/// <summary>
/// very bad function this is so bad i hate it fuck fuck fuck you but i dont want to use some fucking git library thats like 200 mb and requires external linking
/// fuc this :sob: :sob: :sob:
/// </summary>
/// <param name="cmd"> - The command to execute.</param>
/// <returns>The command result.</returns>
std::string util::execute(const char* cmd) {
	std::array<char, 128> buffer;
	std::string res;
	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) {
		std::cout << "[!] FATAL - popen() failed (util::execute)\n";
		throw std::runtime_error("popen() failed");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		res += buffer.data();
	}
	return res;
}