#include "repo.hpp"

bool repo::DownloadBranch(std::string szBranchName) {
	std::string szCommand = "mkdir RatPoison && git clone https://github.com/TheRatCode/RatPoison --depth 1 --branch " + szBranchName;
	const char* szBuffer = szCommand.c_str();
	std::system(szBuffer);
	return true;
}