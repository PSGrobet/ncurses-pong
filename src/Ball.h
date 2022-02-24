#ifndef BALL_H
#define BALL_H

#include <ncurses.h>

class Ball
{
	double xPos{};
	double yPos{};
	int speed{};

	public:
	Ball( double xPos, double yPos, int speed );

	int ballTexture{};
	double getX();
	double getY();
	int getSpeed();
	void setX( double x );
	void setY( double y );
	void setSpeed( int sp );
	void drawBall( double x, double y );
};
#endif
