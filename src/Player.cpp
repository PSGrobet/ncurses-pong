#include <ncurses.h>

#include "Player.h"

//Constructor
Player::Player( int x, int y )
    : xPos(x), yPos(y) {}


int Player::getX()
{
	return xPos;
}

void Player::drawPlayer()
{
	for( int i = 0; i < length; i++ )
	{
		mvaddch(positionArray[i], xPos, pTexture);
	}
}

void Player::setPositionArray( int y ) 
{ 
	for( int i = 0; i < 5; i++ )
	{ 
		positionArray[i] = y + i;
	}
}

int Player::getPoints()
{
	return points;
}

int Player::getY()
{
	return yPos;
}

void Player::setY( int y )
{
	yPos = y;
}

void Player::setPoints( int p )
{
	points = p;
}
