#include<stdio.h>
char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int checkwin(){
    for(int i=0;i<3;i++){
        if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2]){
            printf("%c wins",arr[i][0]);
            return 1;
        }
    }
    for(int i=0;i<3;i++){
        if(arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i]){
            printf("%c wins",arr[0][i]);
            return 1;
        }
    }
    if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]){
        printf("%c wins",arr[0][0]);
        return 1;
    }
    if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]){
        printf("%c wins",arr[1][1]);
        return 1;
    }
    else{
        printf("draw");
    }
    return 0;
}