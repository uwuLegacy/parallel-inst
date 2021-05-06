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
	try {
		std::ofstream script("gradlew.bat");
#pragma region"gradle script"
		const char* scriptText = R"""(
@if "%DEBUG%" == "" @echo off
@rem ##########################################################################
@rem
@rem  Gradle startup script for Windows
@rem
@rem ##########################################################################

@rem Set local scope for the variables with windows NT shell
if "%OS%"=="Windows_NT" setlocal

set DIRNAME=%~dp0
if "%DIRNAME%" == "" set DIRNAME=.
set APP_BASE_NAME=%~n0
set APP_HOME=%DIRNAME%

@rem Add default JVM options here. You can also use JAVA_OPTS and GRADLE_OPTS to pass JVM options to this script.
set DEFAULT_JVM_OPTS=

@rem Find java.exe
if defined JAVA_HOME goto findJavaFromJavaHome

set JAVA_EXE=java.exe
%JAVA_EXE% -version >NUL 2>&1
if "%ERRORLEVEL%" == "0" goto init

echo.
echo ERROR: JAVA_HOME is not set and no 'java' command could be found in your PATH.
echo.
echo Please set the JAVA_HOME variable in your environment to match the
echo location of your Java installation.

goto fail

:findJavaFromJavaHome
set JAVA_HOME=%JAVA_HOME:"=%
set JAVA_EXE=%JAVA_HOME%/bin/java.exe

if exist "%JAVA_EXE%" goto init

echo.
echo ERROR: JAVA_HOME is set to an invalid directory: %JAVA_HOME%
echo.
echo Please set the JAVA_HOME variable in your environment to match the
echo location of your Java installation.

goto fail

:init
@rem Get command-line arguments, handling Windows variants

if not "%OS%" == "Windows_NT" goto win9xME_args

:win9xME_args
@rem Slurp the command line arguments.
set CMD_LINE_ARGS=
set _SKIP=2

:win9xME_args_slurp
if "x%~1" == "x" goto execute

set CMD_LINE_ARGS=%*

:execute
@rem Setup the command line

set CLASSPATH=%APP_HOME%\gradle\wrapper\gradle-wrapper.jar

@rem Execute Gradle
"%JAVA_EXE%" %DEFAULT_JVM_OPTS% %JAVA_OPTS% %GRADLE_OPTS% "-Dorg.gradle.appname=%APP_BASE_NAME%" -classpath "%CLASSPATH%" org.gradle.wrapper.GradleWrapperMain %CMD_LINE_ARGS%

:end
@rem End local scope for the variables with windows NT shell
if "%ERRORLEVEL%"=="0" goto mainEnd

:fail
rem Set variable GRADLE_EXIT_CONSOLE if you need the _script_ return code instead of
rem the _cmd.exe /c_ return code!
if  not "" == "%GRADLE_EXIT_CONSOLE%" exit 1
exit /b 1

:mainEnd
if "%OS%"=="Windows_NT" endlocal

:omega
	)""";
#pragma endregion
		script << scriptText;
		std::cout << "[+] gradle wrapper present\n";
	}
	catch (std::exception& err) {
		std::cout << "[-] Error while creating gradle script: " << err.what() << '\n';
		return false;
	}
	return true;
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