#include <ncurses.h>

#include "Player.h"

//Constructor
Player::Player(int x)
    : xPos(x) {}

void Player::newPosition(int *posArray[], int dir, int size)
{
	for( int i = 0; i < size; i++ )
	{
		posArray[i] += dir;
	}
}

int Player::getX()
{
	return xPos;
}

void Player::drawPlayer()
{
	for(int i = 0; i < length; i++)
	{
		mvaddch(positionArray[i], xPos, pTexture);
	}
}

void Player::setPositionArray( int y)
{
	
	for(int i = 0; i < 5; i++)
	{
		positionArray[i] = y + i;
	}
	
}


// int Player::getYArray() 
// {
// 	return positionArray;
// };
