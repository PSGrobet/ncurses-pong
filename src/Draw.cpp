#include <ncurses.h>
#include <stdlib.h>

#include "Player.h"

void draw( Player playerA, Player playerB )
{
    // caracteres:
    // http://melvilletheatre.com/articles/ncurses-extended-characters/index.html
    int hor_line = ACS_HLINE;
    int ver_line = ACS_VLINE;
    int tl_corner = ACS_ULCORNER;
    int tr_corner = ACS_URCORNER;
    int bl_corner = ACS_LLCORNER;
    int br_corner = ACS_LRCORNER;

    int width = 80;
    int height = 24;

    /*int a[5];
    for( int i = 0; i < 5; i++)
    {
        a[i] = player1_pos[i];
    }
    int b[5];*/
    
    
    erase();

    // Draw the board

    mvaddch( 0, 0, tl_corner);
    mvaddch( 0, width, tr_corner);
    mvaddch( height, 0, bl_corner);
    mvaddch( height, width, br_corner);
    for( int i = 1; i < width; i++ )
    {
        mvaddch(0, i, hor_line );
        mvaddch(height, i, hor_line );
    }

    for( int i = 1; i < height; i++ )
    {
        mvaddch( i, 0, ver_line );
        mvaddch( i, width, ver_line );
    }

    for( int i = 1; i < height; i++ )
    {
        mvaddch( i, width / 2, ':' );
    }

    // drawTest(5, a, 5);

    playerA.drawPlayer();
    playerB.drawPlayer();

    

    refresh();
}
