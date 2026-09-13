#include "rubiks.h"

bool cFile = false;
char fName[32];
int main(int argc, char **argv) {
    Side front, left, right, up, down, back;
    Side cube[6] = {left, front, right, up, down, back};
    
    FILE* file = NULL;
        
    if(argc > 2){
        printf("Error: Too many arguments\n");
        return 1;
    }

    else if(argc == 2){
        if(strlen(argv[1]) > 32){
            printf("Error: File name too large\n");
            return 1;
        }
        file = fopen(argv[1], "r");
        if(file == NULL){
            printf("File not found\n");
            cFile = true;
            fillCube(cube);
        }
        else{
            load(file, cube);
            printf("Successfully loaded %s\n", argv[1]);
        }
        strcpy(fName, argv[1]);   
    }
    else
        fillCube(cube);

    run(file, cube);
    return 0;
}