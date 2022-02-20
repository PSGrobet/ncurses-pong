#include <ncurses.h>
#include "Ball.h"

Ball::Ball( double x, double y, int sp )
	: xPos(x), yPos(y), speed(sp) {}

double Ball::getX() { return xPos; }
double Ball::getY() { return yPos; }
int Ball::getSpeed() { return speed; }

void Ball::setX( double x )
{
	xPos = x;
}

void Ball::setY( double y )
{
	Ball::yPos = y;
}

void Ball::setSpeed( int sp )
{
	speed = sp;
}

void Ball::drawBall( double x, double y )
{
	mvaddch( x, y, ballTexture );
}
