#include "compile.hpp"

bool compile::compile() {
	std::system(".\\gradlew.bat RatPoison");
	return true;
}