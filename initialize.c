#include <ncurses.h>
#include <ctype.h>
#include <unistd.h>
#include <locale.h>
#include "rubiks.h"
#define TRANSPARENT -1

extern bool cFile;
extern char fName[32];
int curry, currx;
int height = 14, width = 29;

void initColors() {
    start_color();
    use_default_colors();
    init_pair(1, COLOR_RED, TRANSPARENT);
    init_pair(2, COLOR_WHITE, TRANSPARENT);
    init_pair(3, COLOR_MAGENTA, TRANSPARENT);
    init_pair(4, COLOR_GREEN, TRANSPARENT);
    init_pair(5, COLOR_BLUE, TRANSPARENT);
    init_pair(6, COLOR_YELLOW, TRANSPARENT);
}



void run(FILE* file, Side cube[]) {
    char string[50];
    Stack undo;   
    //FILE* rbkFile;
    initStack(&undo);
    setlocale(LC_ALL, "");
    initscr();
    initColors();
    curry = (LINES - height) / 2;
    currx = (COLS - width) / 2;
    strcpy(string, " ");
    do {
        clear();
        printCube2(cube, curry, currx);
        if(!isValid(string))
            mvprintw(curry + height-1, currx, "Invalid CMD");
        mvprintw(curry + height-2, currx, "[q] to quit:  ");
        refresh();
        getstr(string);
        cmdCmp(string, cube, &undo, file);
    }   while(strcmp(string, "q") != 0);
    mvprintw(curry + height, currx, "Press any key to exit");
    refresh();
    getch();
    endwin();
}
