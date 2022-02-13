#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>

class Player
{
	int xPos{};
	int pTexture = ACS_VLINE;
	int length = sizeof(positionArray) / sizeof(positionArray[0]);

	public:
		//Constructor
		Player(int x);
		int positionArray[5];
		int getX();
		//int getYArray();
		//void setX(int x);
		//void setY(int y);
		void newPosition(int *posArray[], int dir, int size);
		void drawPlayer();
		void setPositionArray(int y);
		
};



#endif
