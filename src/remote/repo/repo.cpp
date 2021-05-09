#include "repo.hpp"
/// <summary>
/// Downloads the version.txt file from the selected branch and returns the version from the file.
/// </summary>
/// <returns>The version string in the remote repository.</returns>
std::string repo::getVersion() {
	std::string szUrl = "https://github.com/TheRatCode/"
	HRESULT hRes = URLDownloadToFileA(
		FALSE,
		
	)
	std::ifstream curVersionFile("placeholder path");
	if (curVersionFile.good()) {
		std::string curVersion;
		std::getline(curVersionFile, curVersion);
	}
}
/// <summary>
/// Downloads the branch to a subdirectory.
/// </summary>
/// <param name="szBranchName">The branch to download.</param>
/// <returns>True if the download was successful, false if there was an error.</returns>
bool repo::DownloadBranch(std::string szBranchName) {
	try {
		std::string szCommand = "mkdir RatPoison && git clone https://github.com/TheRatCode/RatPoison --depth 1 --branch " + szBranchName;
		const char* szBuffer = szCommand.c_str();
		std::system(szBuffer);
		return true;
	}
	catch (std::exception& err) {
		std::cout << "[!] FATAL - Branch download failed: " << err.what() << '\n';
		return false;
	}
}