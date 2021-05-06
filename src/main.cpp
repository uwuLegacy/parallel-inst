#include "framework.hpp"

int main(int argc, char** argv) {
	/*std::cout << "[>] welcome to parallel installer\n";
	std::cout << "[i] initializing...\n";
	args::setup(argc, argv);
	util::createGradle();
	compile::compile();*/

	std::cout << "[>>>] welcome to parallel installer, debugging feature\n";
	dlmgr::download("https://raw.githubusercontent.com/TheRatCode/RatPoison/we-do-a-little/version.txt", "version.txt");
}