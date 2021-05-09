#pragma once
#include "../../framework.hpp"

namespace repo {
	std::string getVersion();
	bool DownloadBranch(std::string szBranchName);
}