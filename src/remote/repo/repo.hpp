#pragma once
#include "../../framework.hpp"

namespace repo {
	std::string getBuildVersion();
	bool DownloadBranch(std::string szBranchName);
}