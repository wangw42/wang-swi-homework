//
//  main.c
//  snake
//
//  Created by Yqi on 2018/11/29.
//  Copyright © 2018 Pace. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

//snake stepping: dy = -1(up), 1(down); dx = -1(left), 1(right), 0(no move)
void snakeMove(void);
//put a food randomized on a blank cell
void put_money(void);
//out cells of the grid
void output(void);
//outs when gameover
int gameover(void);

char map[12][12] = {
    "************",       //inatial status
    "*XXXXH     *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "************",
};
int snakeLen = 5;
int moneyX;
int moneyY;
int positionX[20] = {1, 1, 1, 1, 1};
int positionY[20] = {5, 4, 3, 2, 1};

int main() {
    //初始化游戏界面
    put_money();
    output();
    
    char move = ' ';
    
    //游戏开始
    while(1){
        scanf(" %c", &move);
        //不加' '的话下一次输入的move为'\n'
        snakeMove();
        if(move == 'w' || move == 'W'){
            positionX[0] -= 1;
            map[positionX[0]][positionY[0]] = 'H';
        }else if(move == 's' || move == 'S'){
            positionX[0] += 1;
            map[positionX[0]][positionY[0]] = 'H';
        }else if(move == 'a' || move == 'A'){
            positionY[0] -= 1;
            map[positionX[0]][positionY[0]] = 'H';
        }else if(move == 'd' || move == 'D'){
            positionY[0] += 1;
            map[positionX[0]][positionY[0]] = 'H';
        }else{
            printf("Unexpected input!\n");
        }
        
        if(positionX[0] == moneyX && positionY[0] == moneyY){
            put_money();
            snakeLen++;
            positionX[snakeLen - 1] = positionX[snakeLen - 2];
            positionY[snakeLen - 1] = positionY[snakeLen - 2];
            map[positionX[snakeLen - 1]][positionY[snakeLen - 1]] = 'X';
        }
        if(!gameover()){
            printf("Game over!\n");
            return 0;
        }else{
            output();
        }
    }
    
    return 0;
}

void put_money(void){
    srand((unsigned)(time(NULL)));
    moneyX = rand()%10+1;
    moneyY = rand()%10+1;
    while(map[moneyX][moneyY] != ' '){
        moneyX = rand()%10+1;
        moneyY = rand()%10+1;
    }
    map[moneyX][moneyY] = '$';
}

void output(void){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void snakeMove(void){
    map[positionX[snakeLen - 1]][positionY[snakeLen - 1]] = ' ';
    for (int i = snakeLen - 1; i > 0; i--) {
        positionX[i] = positionX[i - 1];
        positionY[i] = positionY[i - 1];
        map[positionX[i]][positionY[i]] = 'X';
    }
}

int gameover(void){
    if (positionY[0]==11 || positionY[0]==0) {
        return 0;
    }
    if (positionX[0]==11 || positionX[0]==0) {
        return 0;
    }
    for (int i = 1; i < snakeLen; i++) {
        if (positionY[0] == positionY[i] && positionX[0] == positionX[i]) {
            return 0;
        }
    }
    return 1;
}
