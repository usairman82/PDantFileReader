#include "PDanTGameStructure.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>

#ifndef __PDANTREADER_H
#define __PDANTREADER_H



class PdantReader
{

	public:
	//Constructor and Destructor
		   PdantReader();
		   PdantReader(string sGameFileName);
		  ~PdantReader();
	bool   LoadGameFile(string sGameFileName);
	//Public Methods.


	//Public Data Members
	
	private:
	//Private Data Members

		   PdantGame mGame;

	//Private Methods.

};


#endif