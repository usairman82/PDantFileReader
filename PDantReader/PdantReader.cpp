/***************************************************************************************
Author     : Casey B. Cessnun  					                Created On  : 04-06-2010
File Name  : PdantReader.cpp								    Last Revised: 04-06-2010
Description: This class is designed to read a PDanT game file.  It also 
has functionality to accept a hash value and export an array containing
all game tiles.



****************************************************************************************/
#include "PdantReader.h"

PdantReader::PdantReader(string sGameFileName)
{
	LoadGameFile(sGameFileName);
}

bool PdantReader::LoadGameFile(string sGameFileName)
{
	size_t   returnSize = 0;					 //An value indicating the number of bytes read.
	FILE* lpFile	  = NULL;

	lpFile = fopen(sGameFileName.c_str(),"rb");  //Open file for reading in Binary Mode.

	returnSize = fread(&mGame,PDANT_GAME_FILE_SIZE,1,lpFile); //Load the contents of the file into the struct.

	return (returnSize == PDANT_GAME_FILE_SIZE);
}
PdantReader::PdantReader()
{
}

PdantReader::~PdantReader()
{
}