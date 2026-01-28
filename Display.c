#include <stdio.h>
#include "checkwin.h"

void display(char board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %c ",board[i][j]);
            if(j<2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("---+---+---\n");
    }
}

// assume checkwin(board) is written in another file or above

int main(){ 
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    int valid;
    char move;
    int turn = 0;

    while(turn < 9){
        valid = 0;
        display(board);

        if(turn % 2 == 0)
            printf("Place your X: ");
        else
            printf("Place your O: ");

        while(valid == 0){
            scanf(" %c", &move);

            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[i][j] == move){
                        board[i][j] = (turn % 2 == 0) ? 'X' : 'O';
                        valid = 1;
                    }
                }
            }

            if(valid == 0)
                printf("Invalid move, try again: ");
        }

        // 🔽 HERE is where checkwin goes
        if(checkwin(board)){
            display(board);
            printf("Player %c wins!\n", (turn % 2 == 0) ? 'X' : 'O');
            break;
        }

        turn++;
    }

    if(turn == 9)
        printf("It's a draw!\n");

    return 0;
}
