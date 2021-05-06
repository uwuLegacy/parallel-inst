#include "framework.hpp"

int main(int argc, char** argv) {
#pragma region Argument parsing
	argparse::ArgumentParser parser("parallels-installer");
	CSettings settings;

	parser.add_argument("--skipJdkCheck", "-s")
		.help("Skips checking for JDK")
		.default_value(false)
		.implicit_value(true);
	parser.add_argument("--forceUpdate", "-U")
		.help("Forces cheat update")
		.default_value(false)
		.implicit_value(true);
	parser.add_argument("--forceCompilation", "-C")
		.help("Forces cheat compilation")
		.default_value(false)
		.implicit_value(true);
	try {
		parser.parse_args(argc, argv);
	}
	catch (const std::runtime_error& err) {
		std::cout << "Error while parsing args: " << err.what() << std::endl;
		std::cout << parser;
		exit(0);
	}

	if (parser["--skipJdkCheck"] == true)
		settings.skipJdkCheck = true;
	if (parser["--forceUpdate"] == true)
		settings.forceUpdate = true;
	if (parser["--forceCompilation"] == true)
		settings.forceCompilation = true;
#pragma endregion

	std::cout << "[>] welcome to paralell installer ]\n";
	std::cout << "[i] initializing...\n";
	util::createGradle();
	std::cout << "[+] gradle wrapper present\n";
	std::cout << "[;] starting compilation\n";
	compile::compile();
}