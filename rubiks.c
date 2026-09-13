#include "rubiks.h"

/*
**********************************************************************************************
                                        CLOCKWISE
**********************************************************************************************
*/
void Up(Side cube[]) {
    const int y = 0;
    Side cube2[6];
    copyCube(cube, cube2);
    for(int s = 0; s < 6; s++) {
        int c;
        if(s == 0){
            for(c = 0; c < SIDEMAX; c++)
                cube[s+5].s[y][c] = cube2[s].s[y][c];
        }
        else if(s < 3){
            for(c = 0; c < SIDEMAX; c++)
                cube[s-1].s[y][c] = cube2[s].s[y][c];
        }
        
        if(s == 3) {   //up rotation ccw
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[j][2-i] = scp.s[i][j];
        }
        
        if(s == 4)
            continue;
        if(s == 5){
            for(c = 0; c < SIDEMAX; c++)
                cube[s-3].s[y][c] = cube2[s].s[y][c];
        }
        
    }
}

void Down(Side cube[]) {
    const int y = 2;
    Side cube2[6];
    copyCube(cube, cube2);
    for(int s = 0; s < 6; s++) {
        int c = 0;
        if(s < 2){
            for(c = 0; c < SIDEMAX; c++)
                cube[s+1].s[y][c] = cube2[s].s[y][c];
        }
        
        if(s == 2){    //change contents of back from right
            for(c = 0; c < SIDEMAX; c++)
                cube[s+3].s[y][c] = cube2[s].s[y][c];
        }
        
        if(s == 3) {   //up rotation ccw
            continue;
        }
        
        if(s == 4){
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[j][2-i] = scp.s[i][j];
        }

        if(s == 5){
            for(c = 0; c < SIDEMAX; c++)
                cube[s-5].s[y][c] = cube2[s].s[y][c];
        }
        
    }
}

void Left(Side cube[]) {
    const int y = 2;
    Side cube2[6];
    copyCube(cube, cube2);
    int c = 0;
    int col = 2;
    for(int s = 0; s < 6; s++) {
        
        if(s == 0){
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[j][2-i] = scp.s[i][j];
        }
        
        if(s == 1){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s].s[i][c] = cube2[s+2].s[i][c];
        }

        if(s == 2){    //change contents of back from right
            continue;
        }
        
        if(s == 3){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s].s[i][c] = cube2[s+2].s[2-i][col];
        }

        if(s == 4){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s].s[i][c] = cube2[s-3].s[i][c];
        }

        if(s == 5){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s].s[i][col] = cube2[s-1].s[2-i][c];
        }
        
    }
}

void Right(Side cube[]) {
    const int y = 2;
    Side cube2[6];
    copyCube(cube, cube2);
    const int c = 0;
    const int col = 2;
    for(int s = 0; s < 6; s++) {
        
        if(s == 0){
            continue;
        }
        
        if(s == 1){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s].s[i][col] = cube2[s+3].s[i][col];
        }

        if(s == 2){    //change contents of back from right
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[j][2-i] = scp.s[i][j];
            
        }
        
        if(s == 3){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s].s[i][col] = cube2[s-2].s[i][col];
        }

        if(s == 4){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s].s[2-i][col] = cube2[s+1].s[i][c];
        }

        if(s == 5){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s].s[2-i][c] = cube2[s-2].s[i][col];
        }
        
    }
}

void Front(Side cube[]) {
    const int y = 0, col = 2;
    int c;
    Side cube2[6];
    copyCube(cube, cube2);
    for(int s = 0; s < 6; s++) {
        
        if(s == 0){
            for(c = 0; c < SIDEMAX; c++)
                cube[s].s[c][col] = cube2[s+4].s[y][c];
        }
        if(s == 1){     //up rotation ccw
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[j][2-i] = scp.s[i][j];
        }
        
        if(s == 2) {   
            for(c = 0; c < SIDEMAX; c++)
                cube[s].s[c][y] = cube2[s+1].s[col][c];
        }
        
        if(s == 3) {
            for(c = 0; c < SIDEMAX; c++)
                cube[s].s[col][c] = cube2[s-3].s[2-c][col];
        }

        if(s == 4) {
            for(c = 0; c < SIDEMAX; c++)
                cube[s].s[y][c] = cube2[s-2].s[2-c][y];
        }
        if(s == 5){
            continue;
        }
        
    }
}

void Back(Side cube[]) {
    const int y = 0, col = 2;
    int c;
    Side cube2[6];
    copyCube(cube, cube2);
    for(int s = 0; s < 6; s++) {
        
        if(s == 0){
            for(c = 0; c < SIDEMAX; c++)
                cube[s+4].s[col][c] = cube2[s].s[c][y];
        }
        if(s == 1){     //up rotation ccw
            continue;
        }
        
        if(s == 2) {
            for(c = 0; c < SIDEMAX; c++)
                cube[s+1].s[y][c] = cube2[s].s[c][col];
            
        }
        
        if(s == 3) {
            for(c = 0; c < SIDEMAX; c++)
                cube[s-3].s[2-c][y] = cube2[s].s[y][c];
        }

        if(s == 4){
            for(c = 0; c < SIDEMAX; c++)
                cube[s-2].s[2-c][col] = cube2[s].s[col][c];
        }
        if(s == 5){
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[j][2-i] = scp.s[i][j];
        }
        
    }
}
/*
**********************************************************************************************
                                    COUNTERCLOCKWISE
**********************************************************************************************
*/

void UpP(Side cube[]) {
    const int y = 0;
    Side cube2[6];
    copyCube(cube, cube2);
    for(int s = 0; s < 6; s++) {
        int c;
        if(s == 0){
            for(c = 0; c < SIDEMAX; c++)
                cube[s+1].s[y][c] = cube2[s].s[y][c];
        }
        if(s == 1){
            for(c = 0; c < SIDEMAX; c++)
                cube[s+1].s[y][c] = cube2[s].s[y][c];
        }
        if(s == 2){
            for(c = 0; c < SIDEMAX; c++)
                cube[s+3].s[y][c] = cube2[s].s[y][c];
        }
        
        if(s == 3) {   //up rotation ccw
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[2-j][i] = scp.s[i][j];
        }
        
        if(s == 4)
            continue;
        if(s == 5){
            for(c = 0; c < SIDEMAX; c++)
                cube[s-5].s[y][c] = cube2[s].s[y][c];
        }
        
    }
}

void DownP(Side cube[]) {
    const int y = 2;
    Side cube2[6];
    copyCube(cube, cube2);
    for(int s = 0; s < 6; s++) {
        int c = 0;
        if(s == 0){
            for(c = 0; c < SIDEMAX; c++)
                cube[s+5].s[y][c] = cube2[s].s[y][c];
        }
        if(s == 1){
            for(c = 0; c < SIDEMAX; c++)
                cube[s-1].s[y][c] = cube2[s].s[y][c];
        }
        
        if(s == 2){    //change contents of back from right
            for(c = 0; c < SIDEMAX; c++)
                cube[s-1].s[y][c] = cube2[s].s[y][c];
        }
        
        if(s == 3) {   //up rotation ccw
            continue;
        }
        
        if(s == 4){
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[2-j][i] = scp.s[i][j];
        }

        if(s == 5){
            for(c = 0; c < SIDEMAX; c++)
                cube[s-3].s[y][c] = cube2[s].s[y][c];
        }
        
    }
}
void LeftP(Side cube[]) {
    const int y = 2;
    Side cube2[6];
    copyCube(cube, cube2);
    int c = 0;
    int col = 2;
    for(int s = 0; s < 6; s++) {
        
        if(s == 0){
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[2-j][i] = scp.s[i][j];
        }
        
        if(s == 1){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s+2].s[i][c] = cube2[s].s[i][c];
        }

        if(s == 2){    //change contents of back from right
            continue;
        }
        
        if(s == 3){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s+2].s[2-i][col] = cube2[s].s[i][c];
        }

        if(s == 4){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s-3].s[i][c] = cube2[s].s[i][c];
        }

        if(s == 5){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s-1].s[2-i][c] = cube2[s].s[i][col];
        }
        
    }
}

void RightP(Side cube[]) {
    const int y = 2;
    Side cube2[6];
    copyCube(cube, cube2);
    const int c = 0;
    const int col = 2;
    for(int s = 0; s < 6; s++) {
        
        if(s == 0){
            continue;
        }
        
        if(s == 1){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s+3].s[i][col] = cube2[s].s[i][col];
        }

        if(s == 2){    //change contents of back from right
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[2-j][i] = scp.s[i][j];
            
        }
        
        if(s == 3){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s-2].s[i][col] = cube2[s].s[i][col];
        }

        if(s == 4){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s+1].s[2-i][c] = cube2[s].s[i][col];
        }

        if(s == 5){
            for(int i = 0; i < SIDEMAX; i++) 
                cube[s-2].s[2-i][col] = cube2[s].s[i][c];
        }
        
    }
}
void FrontP(Side cube[]) {
    const int y = 0, col = 2;
    int c;
    Side cube2[6];
    copyCube(cube, cube2);
    for(int s = 0; s < 6; s++) {
        
        if(s == 0){
            for(c = 0; c < SIDEMAX; c++)
                cube[s+4].s[y][c] = cube2[s].s[c][col];
        }
        if(s == 1){     //up rotation ccw
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[2-j][i] = scp.s[i][j];
        }
        
        if(s == 2) {   
            for(c = 0; c < SIDEMAX; c++)
                cube[s+1].s[col][c] = cube2[s].s[c][y];
        }
        
        if(s == 3) {
            for(c = 0; c < SIDEMAX; c++)
                cube[s-3].s[2-c][col] = cube2[s].s[col][c];
        }

        if(s == 4) {
            for(c = 0; c < SIDEMAX; c++)
                cube[s-2].s[2-c][y] = cube2[s].s[y][c];
        }
        if(s == 5){
            continue;
        }
        
    }
}

void BackP(Side cube[]) {
    const int y = 0, col = 2;
    int c;
    Side cube2[6];
    copyCube(cube, cube2);
    for(int s = 0; s < 6; s++) {
        
        if(s == 0){
            for(c = 0; c < SIDEMAX; c++)
                cube[s+3].s[y][2-c] = cube2[s].s[c][y];
        }
        if(s == 1){     //up rotation ccw
            continue;
        }
        
        if(s == 2) {
            for(c = 0; c < SIDEMAX; c++)
                cube[s+2].s[col][2-c] = cube2[s].s[c][col];
            
        }
        
        if(s == 3) {
            for(c = 0; c < SIDEMAX; c++)
                cube[s-1].s[c][col] = cube2[s].s[y][c];
        }

        if(s == 4){
            for(c = 0; c < SIDEMAX; c++)
                cube[s-4].s[c][y] = cube2[s].s[col][c];
        }
        if(s == 5){
            Side scp;
            copySide(&(cube2[s]), &scp);
            for(int i = 0; i < SIDEMAX; i++)
                for(int j = 0; j < SIDEMAX; j++)
                    cube[s].s[2-j][i] = scp.s[i][j];
        }
        
    }
}
