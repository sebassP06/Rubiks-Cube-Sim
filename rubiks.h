#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define SIDEMAX 3
#define LEFT    0
#define FRONT   1
#define RIGHT   2
#define UP      3
#define DOWN    4
#define BACK    5
#define LEFTP   6
#define FRONTP  7
#define RIGHTP  8
#define UPP     9
#define DOWNP   10
#define BACKP   11



typedef struct{
    char s[3][3];
}Side;

typedef struct{
    int ht, wth;
}Coord;


//Printing/Copying
void printRow(Side, const int, int y, int x);
void fillChar(int row, int col, Side * side, char c);
void fillSide(Side *side, const char c);
void fillCube(Side *cube);
void printCube2(Side *cube, int y, int x);
void copyCube(Side c[], Side cc[]);
void copySide(Side* ps1, Side* ps2);

//Rubik's Cube Logic
void Up(Side cube[]);
void Down(Side cube[]);
void Left(Side cube[]);
void Right(Side cube[]);
void Front(Side cube[]);
void Back(Side cube[]);
void UpP(Side cube[]);
void DownP(Side cube[]);
void LeftP(Side cube[]);
void RightP(Side cube[]);
void FrontP(Side cube[]);
void BackP(Side cube[]);

//Input
bool isValid(char *s);
void cmdCmp(char *string, Side cube[], Stack *stack, FILE* file);

//Initialization
void run(FILE* file, Side cube[]);
void chWrite(char *string, Side cube[],FILE* file);

//File Handling
void writeCube(FILE* f, Side cube[], char *filename);
FILE* createFile(char *fileName);
void load(FILE* f, Side cube[]);