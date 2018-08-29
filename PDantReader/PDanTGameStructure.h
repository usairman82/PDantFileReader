#ifndef __PDANTGAMESTRUCTURE_H
#define __PDANTGAMESTRUCTURE_H

static const size_t PDANT_GAME_FILE_SIZE = 304;

struct PdantGame
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


#endif