#include <stdio.h>
#include "checkwin.h"

int checkwin(char board[3][3]) {
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return 1;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return 1;
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return 1;

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return 1;

    return 0;
}
