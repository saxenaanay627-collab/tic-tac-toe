#include<stdio.h>
#include"checkwin.h"

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
    char board[3][3]={'1','2','3','4','5','6','7','8','9'};
    int valid =0;
    display(board);
    char Player1,Player2;
   
    while(1){
        while(valid!=1){
        printf("Place your EX (Player 1): ");
        scanf(" %c",&Player1);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]!='X' && board[i][j]!='O'){
                    if(board[i][j]==Player1){
                        board[i][j]='X';
                        valid=1;
                    }
                  }
                }
            }   
           
        display(board);
        }
        //Player 2
        while(valid!=1){
        printf("Place your O (Player 2): ");
        scanf(" %c",&Player2);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]!='X' && board[i][j]!='O'){
                    if(board[i][j]==Player2){
                        board[i][j]='O';
                        valid=1;
                    }
                }
            }   
        }   
        display(board);
    }
}