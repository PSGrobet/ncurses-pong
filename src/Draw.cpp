#include <ncurses.h>
#include <stdlib.h>

#include "Player.h"
#include "Ball.h"

void draw( Player playerA, Player playerB, Ball ball, int serve )
{
    // caracteres:
    // http://melvilletheatre.com/articles/ncurses-extended-characters/index.html
    int hor_line = ACS_HLINE;
    int ver_line = ACS_VLINE;
    int tl_corner = ACS_ULCORNER;
    int tr_corner = ACS_URCORNER;
    int bl_corner = ACS_LLCORNER;
    int br_corner = ACS_LRCORNER;

    int width{ 80 };
    int height{ 24 };
    int top{ 2 };
    int bottom{ height + 2 }; 
    
    erase();

    // Draw the board
    mvaddch( top, 0, tl_corner);
    mvaddch( top, width, tr_corner);
    mvaddch( bottom, 0, bl_corner);
    mvaddch( bottom, width, br_corner);
    for( int i = 1; i < width; i++ )
    {
        mvaddch( top, i, hor_line );
        mvaddch( bottom, i, hor_line );
    }

    for( int i = 3; i < bottom; i++ )
    {
        mvaddch( i, width / 2, ':' );
    }

    mvprintw( 1, width / 2 / 2, "%i", playerA.getPoints() );
    mvprintw( 1, width / 2 + width / 2 / 2, "%i", playerB.getPoints() );
	
    playerA.drawPlayer();
    playerB.drawPlayer();
    
    if( serve == 0 )
    {
		ball.drawBall(ball.getY(), ball.getX());
		mvprintw( 1, width / 2 - 7, "Player 1 serve");
	} else if ( serve == 1 )
	{
		ball.drawBall(ball.getY(), ball.getX());
		mvprintw( 1, width / 2 - 7, "Player 2 serve"); 
	} else
	{
		ball.drawBall(ball.getY(), ball.getX());
		mvprintw( 1, width / 2 - 7, "Ball speed: %i", ball.getSpeed());
	}	

    refresh();
}
