#include <ncurses.h>
#include "rubiks.h"


void printSquare(int pairNum, int y, int x) {
    attron(COLOR_PAIR(pairNum));
    mvprintw(y, x, "\u25A0");
    attroff(COLOR_PAIR(pairNum));
}

void printRow(Side side, const int row, int y, int x) {
    
    for(int col = 0;col < SIDEMAX; col++, x+=2) {
        char c = side.s[row][col];
        switch (c) {
            case 'R':
            printSquare(1, y, x);
            break;
            case 'W':
            printSquare(2, y, x);
            break;
            case 'M':
            printSquare(3, y, x);
            break;
            case 'G':
            printSquare(4, y, x);
            break;
            case 'B':
            printSquare(5, y, x);
            break;
            default:
            printSquare(6, y, x);
            break;
        }
        printw(" ");
    }
}

void fillChar(int row, int col, Side * side, char c){
    side->s[row][col] = c;
}

void fillSide(Side *side, char c) {
    for(int x = 0; x < SIDEMAX; x++)
        for(int y = 0; y < SIDEMAX; y++)
            fillChar(x, y, side, c);   
}

void fillCube(Side *cube){
    fillSide(&(cube[0]), 'R');
    fillSide(&(cube[1]), 'W');
    fillSide(&(cube[2]), 'M');
    fillSide(&(cube[3]), 'G');
    fillSide(&(cube[4]), 'B');
    fillSide(&(cube[5]), 'Y');  
}
/*          DOESN'T WORK
void printCube(Side *cube, int y, int x){
    printw("  L\t  F\t  R\t  U\t  D\t  B\n");
    for(int row = 0; row < SIDEMAX; row++){
        for(int i = 0; i < 6; i++) {
            printRow(cube[i], row, y, x);
            printw("\t");
        }
        printw("\n");
    }
}
*/
void printCube2(Side *cube, int y, int x){

    int xstart = x;
    int row;
    //Up
    x += 8; // '\t'
    mvprintw(y, x, "  U\n");
    y++; // '\n'
    
    for(row = 0; row < SIDEMAX; row++, y++){
        printRow(cube[3], row, y, x);
    }
    // L, F, R, B
    x = xstart;
    mvprintw(y, x, "  L");
    mvprintw(y, x+=8, "  F");
    mvprintw(y, x+=8, "  R");
    mvprintw(y, x+=8, "  B");
    x = xstart;
    y++;
    for(row = 0; row < SIDEMAX; row++, y++){
        for(int i = 0; i < SIDEMAX; i++) {
            printRow(cube[i], row, y, x);
            x += 8;
        }
        printRow(cube[5], row, y, x);
        x = xstart;
       
    } 
    //Down
    x += 8;
    mvprintw(y, x, "  D");
    y++;
    for(row = 0; row < SIDEMAX; row++){
        printRow(cube[4], row, y++, x);
    }

}

void copyCube(Side c[], Side cc[]) {
    for(int x = 0; x < 6; x++) 
        cc[x] = c[x];
}

void copySide(Side* ps1, Side* ps2) {
    for(int x = 0; x < SIDEMAX; x++)
        for(int y = 0; y < SIDEMAX; y++)
            ps2->s[x][y] = ps1->s[x][y];
}