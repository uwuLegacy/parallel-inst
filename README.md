# parallel-inst
A custom [RatPoison](https://github.com/TheRatCode/RatPoison) installer in C++17. Made to replace the crappy Python installer that doesn't work half the time.

Does not have any dependencies that need to be installed manually (everything thirdparty is in ./src/deps).

Features so far:
  * makes gradle.bat for you
  * compiles the hack

Updates planned and random notes:
  * automatically clone repo if not found
  * change branches tech
  * pull updates from selected branch 
  * store selected branch and other stuff in registry? .ini file? .json file? i wanna use registry cuz then its single file i think
