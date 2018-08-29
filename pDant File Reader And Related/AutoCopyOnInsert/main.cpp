//--------------------------------------------------------------------------
//File Name		: main.cpp
//Author		: Chasm
//Date			: 03/26/2010
//Last Modified : 03/26/2010
//Major Version : 1
//Minor Version : 0
//Description   : This is a simple utility to copy the contents of a
//directory to a USB Key.
//--------------------------------------------------------------------------

#include <vector>
#include "Constants.h"
#include "Tools.h"

int main (int argc, char* argv[])
{

	using namespace std;
  
	int				results			= 0;
	string			directory		= "";
	string			inputBuffer		= "";
	string			inputFileDir    = "";
	string			srcFileName		= "";
	string			dstFileName		= "";
	ifstream		inputFile;

	//User for FindFirst,FindNext, and FindClose
	 long			filePtr			= 0;
	_finddata_t		fileInfo;

	
	if (argc < 3)
	{
		printMessage(argc,argv,STR_USAGE);
	}
	else
	{
		if (argc >=4)
		{
			if (strcmp(argv[3],"-s") == 0 || strcmp(argv[3],"-S") == 0)
			{
				hideWindow(argv);
			}
		}

		inputFile.open(argv[1],ios::in);

		if (inputFile.is_open())
		{

			do
			{
				getline(inputFile,inputBuffer);

				if (access(inputBuffer.c_str(),0) == 0)
				{
					struct stat status;
					stat( inputBuffer.c_str(), &status );

					if ( status.st_mode & S_IFDIR )
					{
						printMessage(argc,argv,STR_FILE_FOUND);

						inputFileDir = inputBuffer + "\\" + argv[2];
						//Directory Was Located: Begin Copying Game Files
						filePtr = _findfirst(inputFileDir.c_str(),&fileInfo);

						if (filePtr != -1)
						{
							do
							{
								srcFileName = inputBuffer + "\\\\" + fileInfo.name;
								//cout << argv[0] << endl;
								if (argc >=5)
								{
									dstFileName = argv[4];
									dstFileName +="\\";
								}
								else
								{
									//dstFileName = argv[0];
									//dstFileName = dstFileName.substr(0,dstFileName.find_last_of("\\"))+"\\DTLD\\";
									  dstFileName = ".\\DTLD\\";
								}

								dstFileName.append(fileInfo.name);
								//cout << dstFileName << endl;

								if (copyFile(srcFileName,dstFileName) !=0)
								{
									printMessage(argc,argv,STR_ERROR_COULD_NOT_COPY_PT1+fileInfo.name+STR_ERROR_COULD_NOT_COPY_PT2);
									return 0;
								}

							}while (_findnext(filePtr,&fileInfo)  >=0);
						}
						else
						{
							printMessage(argc,argv,STR_ERROR_COULD_NOT_OPEN_DIR);
							return 0;
						}

						break;
					}
					
				}
				
			} while (!inputFile.eof());
		}
		else
		{
			printMessage(argc,argv,STR_ERROR_NO_INPUT_FILE);
			return 0;
		}
	}

return 0;
}
