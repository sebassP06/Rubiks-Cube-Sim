#include <ncurses.h>
#include <ctype.h>
#include <unistd.h>
#include "rubiks.h"

extern int curry, currx;
extern int height, width;

void chWrite(char *string, Side cube[], FILE* file){
    extern bool cFile;
    extern char fName[32];
    if(file == NULL){
        if(!cFile){
            clear();
            printCube2(cube, curry, currx);
            mvprintw(curry + height-2, currx, "Type Desired Filename: ");
            //refresh();
            getstr(string);
            writeCube(file, cube, string);
            mvprintw(curry + height-1, currx, "Saved as %s.rbk", string);
        }
        else{
            writeCube(file, cube, fName);
            mvprintw(curry + height-2, currx, "Saved to %s", fName);
        }
    }
    else{
        writeCube(file, cube, fName);
        mvprintw(curry + height-2, currx, "Saved to %s", fName);
    }
        
}


bool isValid(char *s) {
    char *dict[] = {"", " ", "u", "u'", "d", "d'", "l",
                    "l'", "r", "r'", "f", "f'", "b", 
                    "b'", "undo", "solve", "scram", "w",
                    "wq", "mv", NULL};
        for(int i = 0; dict[i] != NULL; i++) {
            if(strcmp(s, dict[i]) == 0)
                return true;
        }
    return false;
}

void stackCmp(Side cube[], int num){
    switch (num) {
        case LEFT:
            Left(cube);
            break;
        case FRONT:
            Front(cube);
            break;
        case RIGHT:
            Right(cube);
            break;
        case UP:
            Up(cube);
            break;
        case DOWN:
            Down(cube);
            break;
        case BACK:
            Back(cube);
            break;  
        case LEFTP:
            LeftP(cube);
            break;
        case FRONTP:
            FrontP(cube);
            break;
        case RIGHTP:
            RightP(cube);
            break;
        case UPP:
            UpP(cube);
            break;
        case DOWNP:
            DownP(cube);
            break;
        case BACKP:
            BackP(cube);
            break;
        default:
            break;
    }
}


void solve(Side cube[], Stack *stack) {
    while(stack->top != -1) {
        stackCmp(cube, pop(stack));
    }
}

void scramble(Side cube[], Stack *stack){
    int upper_bound = 11;
    for (int i = 0; i < 50; i++) {
        int value = rand() % (upper_bound + 1);
        stackCmp(cube, value);
        if(value < 6)
            value += 6;
        else
            value -= 6;
        push(stack, value);
    }
}


void cmdCmp(char *string, Side cube[], Stack *stack, FILE* file) {
    for(int i = 0; string[i]; i++)
        string[i] = tolower(string[i]);
    
        if(strcmp(string, "u") == 0){
            Up(cube);
            push(stack, UPP);
        }
        else if(strcmp(string, "u'") == 0){   
            UpP(cube);
            push(stack, UP);
        }
        else if(strcmp(string, "d") == 0){   
            Down(cube);
            push(stack, DOWNP);
        }
        else if(strcmp(string, "d'") == 0){   
            DownP(cube);
            push(stack, DOWN);
        }
        else if(strcmp(string, "b") == 0){   
            Back(cube);
            push(stack, BACKP);
        }
        else if(strcmp(string, "b'") == 0){   
            BackP(cube);
            push(stack, BACK);
        }
        else if(strcmp(string, "l") == 0){   
            Left(cube);
            push(stack, LEFTP);
        }
        else if(strcmp(string, "l'") == 0){
            LeftP(cube);
            push(stack, LEFT);
        }
        else if(strcmp(string, "r") == 0){   
            Right(cube);
            push(stack, RIGHTP);
        }
        else if(strcmp(string, "r'") == 0){
            RightP(cube);
            push(stack, RIGHT);
        }
        else if(strcmp(string, "f") == 0){   
            Front(cube);
            push(stack, FRONTP);
        }
        else if(strcmp(string, "f'") == 0){   
            FrontP(cube);
            push(stack, FRONT);
        }
        else if(strcmp(string, "undo") == 0){   
            stackCmp(cube, pop(stack));
        }
        else if(strcmp(string, "solve") == 0){   
            solve(cube, stack);
        }
        else if(strcmp(string, "scram") == 0){   
            scramble(cube, stack);
        }
        else if(strcmp(string, "w") == 0){   
            chWrite(string, cube, file);
            strcpy(string, " ");
        }
        else if(strcmp(string, "wq") == 0){   
            chWrite(string, cube, file);
            strcpy(string, "q");
        }

        else if(strcmp(string, "mv") == 0){		
	        keypad(stdscr, TRUE);
            noecho();
            int ch;
            clear();
            printCube2(cube, curry, currx);
            refresh();
            //ESC_KEY = 27
            while((ch = mvgetch(0, 0)) != 27 && ch != 'q'){
                switch(ch){
                    case 'a':
                    case KEY_LEFT:
                        currx--;
                        if(currx < 1)
                            currx = 0;
                        clear();
                        printCube2(cube, curry, currx);
                        break;
                    case 'd':
                    case KEY_RIGHT:
                        currx++;
                        if(currx > (COLS - width))
                            currx = COLS - width;
                        clear();
                        printCube2(cube, curry, currx);
                        break;
                    case 'w':
                    case KEY_UP:
                        curry--;
                        if(curry < 1)
                            curry = 0;                          
                        clear();
                        printCube2(cube, curry, currx);
                        break;
                    case 's':
                    case KEY_DOWN:
                        curry++;
                        if(curry > (LINES - height-1))
                            curry = LINES - height-1;                       
                        clear();
                        printCube2(cube, curry, currx);
                        break;
                    default:
                        break;
                }
                refresh();
            }
            echo();
        }

        else   
            return;
}





