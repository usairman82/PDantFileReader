// PdantReader.cpp : Defines the entry point for the console application.
// V2.0
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstdlib>
struct pDantGame
{
	char gameNum[4];
	char blank_1[8];
	char magicNumberA;
	char magicNumberB;
	char magicNumberC[6];
	char greenCount;
	char blank_2[3];
	char blueCount;
	char blank_3[3];
	char redCount;
	char blank_4[3];
	char gameBoard[264]; //264
	char blank_5[8];

};


char* substr(const char* source,int offset, int size);
char* goUp(const char* source);
std::string CheckTile(int tileNumber,struct pDantGame* game, bool encode=false,bool printHeader=false);
using namespace std;
int main(int argc, char* argv[])
{
	FILE* pDantGameMap;
	
	string games[13][1];
	string code;
	char* fileName = {".\\dt"};
	int blockType = 0;

	struct pDantGame myGame;

	games[0][0] = "";
	int gameFile = 1;
	char *buffer = new char[4];
	char *fullFileName = new char[25];
	
	if (argc > 1)
	{
		pDantGameMap = fopen(argv[1],"rb");
		size_t result = 0;

		
		result = fread(&myGame,304,1,pDantGameMap);
		
		sprintf(buffer,"%i",*myGame.gameNum);
		code = "";

		for (int i =0; i < 66;i++)
		{
			cout << "Game [" << buffer << "] Tile [" << i+1 <<"] is " << CheckTile(i,&myGame) << endl;
		}
	}
	else
	{


		sprintf(fullFileName,"%s%i.dat",fileName,gameFile);

		while (pDantGameMap = fopen(fullFileName,"rb"))
		{
			
			pDantGameMap = fopen(fullFileName,"rb");
			
			size_t result = 0;

			
			result = fread(&myGame,304,1,pDantGameMap);
			
			code = "";

			for (int i =0; i < 18;i++)
			{
				code = code + CheckTile(i,&myGame,true);
			}

			games[gameFile][0] = code;

			fclose(pDantGameMap);
			gameFile++;
			sprintf(fullFileName,"%s%i.dat",fileName,gameFile);
			
		}

	
		
		while (1)
		{
			string userInput = "";
			string userInput2 = "";
			cout << "Please Enter The Code:";
			cin >> userInput;

			for (int i = 0; i <gameFile;i++)
			{
				if (userInput == games[i][0])
				{
					cout << "\nThe Game Is Game:" << i << endl << "View Game Board?";
					cin  >> userInput2;
					if (userInput2 == "Y" || userInput2== "y")
					{
						sprintf(buffer,"%s%i.dat",fileName,i);
						pDantGameMap = fopen(buffer,"rb");
						size_t result = 0;

						
						result = fread(&myGame,304,1,pDantGameMap);
						
						sprintf(buffer,"%i",*myGame.gameNum);
						code = "";

						for (int i =0; i < 66;i++)
						{
							cout << "Game [" << buffer << "] Tile [" << i+1 <<"] is " << CheckTile(i,&myGame) << endl;
						}
						fclose(pDantGameMap);
					}
					break;
				}
			}
		}
	}
	int i = 0;
	return 0;
}

string CheckTile(int tileNumber,struct pDantGame* myGame,bool encode,bool printHeader)
{
		using namespace std;
		int magicNumber = 0, magicNumberB =0, iCheckVal = 0,iCheckValBLC = 0, iCheckValB = 0,iBlockVal = 0,iBlockValB = 0,iBlockValC = 0;
		std::string hex = "";
		char *checkValue = new char[5];
		char *checkValueA = new char[5];
		char *blockColor = new char[6];
		char *checkValueB = new char[5];
		char *magNumA = new char[4];
		char *magNumB = new char[4];
		int iByteTwo   = 0;
		int iByteThree = 0;
		int iCheckValC  = 0;
		int i = 0, j = 0;
		char *checkDigits = new char[4];

		i = tileNumber;
		j = tileNumber*4;
		//-----
	//Turn the magic numbers into something we can use.
	sprintf(checkValueA,"%0.2X\0",myGame->magicNumberA);
	if (strlen(checkValueA) > 2)
	{
		checkValueA = substr(checkValueA,6,2);
		hex = checkValueA;
		
	}
	else
	{
		hex = checkValueA;
	}
	sscanf(hex.c_str(), "%x", &magicNumber);
	


	sprintf(checkValue,"%0.2X",myGame->magicNumberB);
	if (strlen(checkValue) > 2)
	{
		hex = substr(checkValue,6,2);
	}
	else
	{
		hex = checkValue;
	}
	hex = checkValue;
	sscanf(hex.c_str(), "%x", &magicNumberB);


	if(printHeader)
	{
		printf("%0.4X = Game Number.\n",*myGame->gameNum);
		printf("%s = Magic Number 1.(Int:%i)\n",checkValueA,magicNumber);
		printf("%0.2X = Magic Number 2.\n",myGame->magicNumberB);
		printf("%0.2X = Green Count.\n",myGame->greenCount);
		printf("%0.2X = Blue Count.\n",myGame->blueCount);
		printf("%0.2X = Red Count.\n",myGame->redCount);
	}
		//-----
		char * byteOne = new char[4];
		char * byteTwo = new char[4];
		char * byteThree = new char[4];
		char * byteFour = new char[4];


		byteOne   = _itoa(myGame->gameBoard[j]  ,byteOne  ,16);
		byteTwo   = _itoa(myGame->gameBoard[j+1],byteTwo  ,16);
		byteThree = _itoa(myGame->gameBoard[j+2],byteThree,16);
		byteFour  = _itoa(myGame->gameBoard[j+3],byteFour ,16);

		if (strlen(byteOne) > 2)
		{
			byteOne = substr(byteOne,6,2);
		}
		if (strlen(byteTwo) > 2)
		{
			byteTwo = substr(byteTwo,6,2);
		}
		if (strlen(byteThree) > 2)
		{
			byteThree = substr(byteThree,6,2);
		}
		if (strlen(byteFour) > 2)
		{
			byteFour = substr(byteFour,6,2);
		}
		
		//hex = byteOne;
		//sscanf(hex.c_str(), "%x", &intVal);

		//Get The Two Digits We Care About
		iCheckVal = magicNumber * (i+1);
		iCheckValBLC = iCheckVal;

		sprintf(checkValue,"%0.4X",iCheckVal);

		if (strlen(checkValue) >=4 && (checkValue[0] != '0' || checkValue[1] != '0'))
		{
			checkValue = substr(checkValue,2,2);

			hex = checkValue;
			sscanf(hex.c_str(),"%x",&iCheckVal);
		}

		
		//Convert The Two Digits from byteOne into an int.
		hex = byteOne;
		sscanf(hex.c_str(),"%x",&iBlockVal);


		//It Happens, Though Legal it causes us pain.
		if (iBlockVal < iCheckVal)
		{
			//Use the second magic number to figure out what the value
			//of byte two of the block data should be.


			
			//Check Digit 2
			//hex = byteTwo;
			//sscanf(hex.c_str(),"%x",&iBlockValB);

			//Check Digit 3
			//hex = byteThree;
			//sscanf(hex.c_str(),"%x",&iBlockValC);

			//Get The Check Value
			iCheckValC = (i+1)*magicNumberB;
			
			//iBlockValB + ((Check Digit 3 + iBlockValB)
			sprintf(checkDigits,"%s%s",byteThree,byteTwo);
			
			hex = checkDigits;
			sscanf(hex.c_str(),"%x",&iBlockValB);

			//This should be the first byte of the original Check Value In byteOne
			iCheckValB = iBlockValB - iCheckValC;

			//Get the value of the original check digits
			if (strlen(byteOne) <=1)
			{
				sprintf(checkDigits,"%0.2X0%s",iCheckValB,byteOne);
			}
			else
			{
				sprintf(checkDigits,"%0.2X%s",iCheckValB,byteOne);
			}


			hex = checkDigits;
			sscanf(hex.c_str(),"%x",&iBlockVal);
			
			iCheckVal = iCheckValBLC;
		}

		
		switch (iBlockVal - iCheckVal)
		{
		case 1:
			if (encode)
			{
				sprintf(blockColor,"1");
			}
			else
			{
				sprintf(blockColor,"Green");
			}
			break;
		case 2:
			if (encode)
			{
				sprintf(blockColor,"2");
			}
			else
			{
				sprintf(blockColor,"Blue");
			}
			break;
		case 3:
			if (encode)
			{
				sprintf(blockColor,"3");
			}
			else
			{
				sprintf(blockColor,"Red");
			}
			break;
		default:
			sprintf(blockColor,"Error");
		}


		//printf("Check Sum: %i ",iCheckVal);
		//printf("Block Val: %i\n",iBlockVal);
	
		//printf("Tile #%i = %s %s %s %s Color: %s\n",i+1,byteOne,byteTwo,byteThree,byteFour,blockColor);
		std::string retVal = blockColor;
		return retVal;
}

char* goUp(const char* source)
{
	char* returnValue = new char[strlen(source)+1];
	int i = 0;
	
	for (i = 0; i < (int)strlen(source);i++)
	{
		returnValue[i] = toupper(source[i]);
	}
	
	returnValue[i] = '\0';
	return returnValue;
}

char* substr(const char* source,int offset, int size)
{
	char *temp = new char[size+1];
	int i = 0;
	for (i = 0;i < size; i ++)
	{
		temp[i] = source[offset+i];
	}
	temp[i] = '\0';
	return goUp(temp);
}