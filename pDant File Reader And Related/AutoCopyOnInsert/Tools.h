#ifndef __TOOLS__H
#define __TOOLS__H
#include <iostream>
#include <string>
#include <fstream>
#include <io.h>			 // For access().
#include <sys/types.h>   // For stat().
#include <sys/stat.h>    // For stat().
 #include <windows.h>
//Copy File Utility
void hideWindow(char* argv[]);
int copyFile(std::string source, std::string dest);
void printMessage(int argc, char* argv[], std::string errorMessage);
#endif