#include <ncurses.h>
#include <stdlib.h>
#include "Player.h"
#include "Ball.h"


int ch; // es int porque getch() devuelve el valor ascii del caracter que tecleas
int width = 80;
int height = 24;
char wallTexture;
bool quit;

void setup();
void draw( Player playerA, Player playerB );


int main()
{
    setup();
	Player player1(3);
	Player player2(77);
	//int * arr[5] = {4, 5, 6, 7, 8};
	player1.setPositionArray(6);
	player2.setPositionArray(9);

    while(!quit)
    {
        draw( player1, player2 );
    }
    endwin();
    return 0;
}


void setup()
{
    //Textures
    wallTexture = '*';

    //Init ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(50);

    quit = false;
}

//para usar otro tipo de caracteres, usar UNICODE. http://yjlv.blogspot.com/2015/10/displaying-unicode-with-ncurses-in-c.html#cfd5-setup
