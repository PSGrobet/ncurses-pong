#include <ncurses.h>
#include <stdlib.h>
#include <iostream>

#include "Player.h"
#include "Ball.h"

bool quit;
int ch{};
int playerServe{};

void setup();
void input();
void logic();
void draw( Player playerA, Player playerB, Ball ball, int serve );

Player player1( 3, 12 );
Player player2( 77, 12 );
Ball ball(1, 1, 0);

int serve();

int main()
{
    setup();

    playerServe = serve();
    
		while(!quit)
		{

			logic();
			input();
			draw( player1, player2, ball, playerServe );
		
		}
    endwin();
    
    return 0;
}

void setup()
{
    //Init ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(50);

	ball.ballTexture = 'o';

    player1.pTexture = ACS_VLINE;
	player2.pTexture = ACS_VLINE;
	
	player1.setPoints(0);
	player2.setPoints(0);
	player1.setPositionArray( player1.getY() );
	player2.setPositionArray( player2.getY() );

    quit = false;
}

void input()
{
	ch = getch();

	switch( ch )
	{
		case 'w':
			if( player1.getY() > 3 )
			{
			player1.setY( player1.getY() - 1 );
			player1.setPositionArray( player1.getY() );
			}
			break;
		case 's':
			if( player1.getY() < 21 )
			{
				player1.setY( player1.getY() + 1 );
				player1.setPositionArray( player1.getY() );
			}
			break;
		case KEY_UP:
			if( player2.getY() > 3 )
			{
			player2.setY( player2.getY() - 1 );
			player2.setPositionArray( player2.getY() );
			}
			break;
		case KEY_DOWN:
			if( player2.getY() < 21 )
			{
				player2.setY( player2.getY() + 1 );
				player2.setPositionArray( player2.getY() );
			}
			break;
		case ' ':
			if( playerServe == 0 )
			{
				playerServe = -1;
				ball.setSpeed( 1 );
			} else if( playerServe == 1)
			{
				playerServe = -1;
				ball.setSpeed( -1 );
			}
			break;
		case 'q':
			quit = true;
			break;
	}
}

void logic()
{
	if( playerServe == 0 )
	{
		ball.setX( player1.getX() + 1 );
		ball.setY( player1.getY() + 2 );
	} else if ( playerServe == 1 )
	{
		ball.setX( player2.getX() - 1 );
		ball.setY( player2.getY() + 2 );
	}
	
	if( playerServe != 0 || playerServe != 1 )
	{
		if( ball.getSpeed() == 1 )
		{
			ball.setX( ball.getX() +1 );
		} else if( ball.getSpeed() == -1 )
		{
			ball.setX( ball.getX() -1 );
		}	
	}
}

int serve()
{
	// 0: player 1 serves,
	// 1: player 2 serves.
	int s{};
	srand(time(0));
	s = rand() % 2;

	return s;
}

//para usar otro tipo de caracteres, usar UNICODE. http://yjlv.blogspot.com/2015/10/displaying-unicode-with-ncurses-in-c.html#cfd5-setup
