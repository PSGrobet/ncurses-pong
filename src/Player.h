#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>

class Player
{
	int xPos{};
	int yPos{};	
	int length = sizeof(positionArray) / sizeof(positionArray[0]);
	int points{};
	int positionArray[5];
	
	public:
		//Constructor
		Player(int x, int y);
	
		int getX();
		int getY();
		void setY( int y );
		void drawPlayer();
		void setPositionArray(int y);
		int getPoints();
		void setPoints(int p);
		int pTexture{};
};

#endif
