#include "settings.hpp"

void args::setup(int argc, char** argv) {
	std::cout << "[i] parsing arguments...\n";

	argparse::ArgumentParser parser("parallels-installer");

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
		std::cout << "[-] error while parsing args: " << err.what() << std::endl;
		std::cout << parser;
		exit(0);
	}

	if (parser["--skipJdkCheck"] == true)
		settings.skipJdkCheck = true;
	if (parser["--forceUpdate"] == true)
		settings.forceUpdate = true;
	if (parser["--forceCompilation"] == true)
		settings.forceCompilation = true;
}