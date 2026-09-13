#include "rubiks.h"

void writeSide(FILE* f, Side *side){
    for(int x = 0; x < SIDEMAX; x++)
        for(int y = 0; y < SIDEMAX; y++)
            fprintf(f, "%c", side->s[x][y]);
    fprintf(f, "\n");
}

void writeCube(FILE* f, Side cube[], char *filename){
    if(f == NULL){
        f = createFile(filename);
    }
    for(int x = 0; x < 6; x++)
        writeSide(f, &(cube[x]));
    fclose(f);
}

FILE* createFile(char *fileName){
    FILE* file;
    int len;
    int fileExtMaxLen = 5;
    char fileExten[fileExtMaxLen];
    char buffer[100];
    //fileName length
    len = strlen(fileName); 
    //concatenating file extension
    if(len > 3){
        int j = 0;
        for(int i = len - 4; i < len; i++){
            fileExten[j] = fileName[i];
            j++; 
        }
        fileExten[fileExtMaxLen - 1] = '\0';
        if(strcmp(fileExten, ".rbk") == 0){
            file = fopen(fileName, "w");
            //printf("Created file %s\n", fileName);
        }
        else{
            strcpy(buffer, fileName);
            strcat(buffer, ".rbk");
            file = fopen(buffer, "w");
            //printf("Created file %s\n", buffer);    
        }
    }
    else{
        strcpy(buffer, fileName);
        strcat(buffer, ".rbk");
        file = fopen(buffer, "w");
        //printf("Created file %s\n", buffer);
    }
    return file;
}

void load(FILE* f, Side cube[]){
    int bufLimit = SIDEMAX * 3;
    char buffer[bufLimit+2];
    for(int i = 0;fgets(buffer, bufLimit+2, f); i++){
        //printf("%s", buffer);
        int z = 0;
        for(int x = 0; x < SIDEMAX; x++){
            for(int y = 0; y < SIDEMAX; y++){
                fillChar(x, y, &(cube[i]), buffer[z]);
                z++;
            }
        }
    }
}



