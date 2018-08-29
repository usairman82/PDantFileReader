#include "Tools.h"


//------------------------------------------------
//Author		: Chasm
//Date Created	: 03/27/2010
//Last Modified : 03/27/2010
//File Name     : Tools.cpp
//Description   : This is a tools library to facilitate rapid
//development and code re-usage
//
//Copyright (c) Caseware Computer Systems, LLC
//------------------------------------------------

//------------------------------------------------
//Author		: Chasm
//Function		: copyFile
//In			: char* argv[] - The Command line arguments of the main application being run.
//				  or an array of strings containing the name of the window to be hidden
//				  as the zeroith element.
//Return		: Returns Nothing - Void
//Description   : This function will hide a console window with the name specified as the
//				  zeroith element of an array of strings.
//Created		: 03/27/2010
//Last Modified	: 03.27/2010
//Revisions     : <Date>  <Description>
//--------------------------------------------------
void hideWindow(char* argv[])
{
	HWND hWnd = FindWindow("ConsoleWindowClass",argv[0]);
	ShowWindow(hWnd,SW_HIDE);
}

//------------------------------------------------
//Author		: Chasm
//Function		: copyFile
//In			: std::string source - The source file to be copied
//				  std::string dest   - The destination file to be copied to.
//Return		: int - Returns 0 for success and -1 for failure.
//				  Failures are due to non existent files and directories
//				  or lack of read/write permissions.
//Description	: This function will copy the contents of one binary file
//				  to another.
//Created		: 03/27/2010
//Last Modified	: 03.27/2010
//Revisions     : <Date>  <Description>
//--------------------------------------------------
int copyFile(std::string source, std::string dest)
{
	using namespace std;

	ifstream sourceFile;
	ofstream destFile;

	struct stat sourceResults;
	struct stat destResults;

	sourceFile.open(source.c_str(),ios::binary);
	destFile.open(dest.c_str(),ios::binary);

	if (sourceFile.is_open() && destFile.is_open())
	{

		//Copy The Contents of the sourceFile in Binary Mode
		//to the destination file using if and of streams.
		destFile << sourceFile.rdbuf();

		destFile.close();
		sourceFile.close();

		stat(source.c_str(),&sourceResults);
		stat(dest.c_str(),&destResults);

		if (destResults.st_size == sourceResults.st_size)
		{
			//Looks like everything went as planned
			//Or at least, the files are the same size.
			//--To Do-- An optional fast byte by byte file comparison?
			return 0;
		}
		else
		{
			//The size of the files does not match.
			return -1;
		}
	}
	else
	{
		//One of more of the files did not open.  Return failure.
		return -1;
	}

	//Something unexpected happened return failure.
	return -1;
}


//------------------------------------------------
//Author		: Chasm
//Function		: printMessage
//In			: int argc - The count of command line arguments
//				  char* argv[] - The command line arguments
//				  std::string strMessage - The Message to be displayed.
//Return		: int - Returns 0 for success and -1 for failure.
//				  Failures are due to non existent files and directories
//				  or lack of read/write permissions.
//Description	: This method will print a message after checking for
//				  the lack of an argument informing it to do otherwise.
//Created		: 03/27/2010
//Last Modified	: 03.27/2010
//Revisions     : <Date>  <Description>
//To Do		    : Rewrite for reusability - currently is application dependant.
//--------------------------------------------------
void printMessage(int argc, char* argv[], std::string strMessage)
{
	if (argc >= 4)
	{
		if (strcmp(argv[3],"-S") !=0 && strcmp(argv[3],"-s") !=0)
		{
			std::cout << strMessage;
		}
	}
	else
	{
		std::cout << strMessage;
	}
}