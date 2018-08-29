#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

struct test
{
	char arr[304];
};

char* substr(const char* source,int offset, int size);
void goUp(char* source);

int main(int argc, char * argv[])
{

	test *leakTest;
	string tstStr = "";
	char testVal[5]  = {"01C4"};
	char *temp1 = NULL;
	char *temp2 = NULL;
	char *temp3 = NULL;
	char *temp4 = NULL;
	char *temp5 = NULL;
	char *temp6 = NULL;
	char *temp7 = NULL;
	char *temp8 = NULL;
	char *temp9 = NULL;
	char *temp10 = NULL;
	char *tmpPtr = NULL;
	while (1)
	{
		tstStr = "";
		leakTest = (test*)malloc(sizeof(test));
		for (int i =0; i < 304;i++)
		{
			temp1 = new char[4];
			temp2 = new char[4];
			temp3 = new char[4];
			temp4 = new char[4];
			temp5 = new char[4];
			temp6 = new char[4];
			temp7 = new char[4];
			temp8 = new char[4];
			temp9 = new char[4];
			temp10 = new char[25];

			strcpy(temp10,"hello world");
			tmpPtr = substr(temp10,5,5);
			strcpy(temp10,tmpPtr);
			delete tmpPtr;

			leakTest->arr[i] = '1';
			sscanf(tstStr.c_str(),"%x",testVal);

			delete [] temp1;
			delete [] temp2;
			delete [] temp3;
			delete [] temp4;
			delete [] temp5;
			delete [] temp6;
			delete [] temp7;
			delete [] temp8;
			delete [] temp9;
			delete [] temp10;

		}


		free(leakTest);

	}



return 0;
}

void goUp(char* source)
{
	//char* returnValue = new char[strlen(source)+1];
	int i = 0;
	
	for (i = 0; i < (int)strlen(source);i++)
	{
		source[i] = toupper(source[i]);
	}
	
	//returnValue[i] = '\0';
	//return returnValue;
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
	goUp(temp);
	return temp;
}