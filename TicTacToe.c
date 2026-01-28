#include <stdio.h>

// Function to check for a winner
int checkwin(char board[3][3]) {
    for(int i=0; i<3; i++){
        // Check rows
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && (board[i][0]=='X' || board[i][0]=='O')){
            printf("%c wins!\n", board[i][0]);
            return 1;
        }
        // Check columns
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && (board[0][i]=='X' || board[0][i]=='O')){
            printf("%c wins!\n", board[0][i]);
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && (board[0][0]=='X' || board[0][0]=='O')){
        printf("%c wins!\n", board[0][0]);
        return 1;
    }

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && (board[1][1]=='X' || board[1][1]=='O')){
        printf("%c wins!\n", board[1][1]);
        return 1;
    }

    return 0; // No winner yet
}

// Function to display the board
void display(char board[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf(" %c ", board[i][j]);
            if(j<2) printf("|");
        }
        printf("\n");
        if(i<2) printf("---+---+---\n");
    }
}

// Main function
int main(){ 
    char board[3][3] = {'1','2','3','4','5','6','7','8','9'};
    char Player1, Player2;
    int valid, winner = 0;

    display(board);

    while(!winner){
        // Player 1
        valid = 0;
        while(!valid){
            printf("Place your X (Player 1): ");
            scanf(" %c", &Player1);
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(board[i][j] != 'X' && board[i][j] != 'O' && board[i][j] == Player1){
                        board[i][j] = 'X';
                        valid = 1;
                    }
                }
            }
            if(!valid) printf("Invalid move! Try again.\n");
        }
        display(board);
        winner = checkwin(board);
        if(winner) break;

        // Player 2
        valid = 0;
        while(!valid){
            printf("Place your O (Player 2): ");
            scanf(" %c", &Player2);
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(board[i][j] != 'X' && board[i][j] != 'O' && board[i][j] == Player2){
                        board[i][j] = 'O';
                        valid = 1;
                    }
                }
            }
            if(!valid) printf("Invalid move! Try again.\n");
        }
        display(board);
        winner = checkwin(board);
    }

    return 0;
}
