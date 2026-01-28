#include<stdio.h>

void display(char board[3][3]){
   
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %c ",board[i][j]);
                if(j<2){
                    printf("|");
                }
            } 
            printf("\n");
               if(i < 2){
            printf("---+---+---\n");
               }
        }
      
    }







int main(){ 
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    display(board);

    char move;

    while(1){
        int valid = 0;

        // Player 1
        while(valid != 1){
            printf("Place your X (Player 1): ");
            scanf(" %c", &move);

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(board[i][j] == move){
                        board[i][j] = 'X';
                        valid = 1;
                    }
                }
            }

            if(!valid)
                printf("Invalid move! Try again.\n");
        }

        display(board);

        // RESET valid for Player 2
        valid = 0;

        // Player 2
        while(valid != 1){
            printf("Place your O (Player 2): ");
            scanf(" %c", &move);

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(board[i][j] == move){
                        board[i][j] = 'O';
                        valid = 1;
                    }
                }
            }

            if(!valid)
                printf("Invalid move! Try again.\n");
        }

        display(board);
    }

    return 0;
}