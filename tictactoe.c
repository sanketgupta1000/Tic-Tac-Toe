#include<stdio.h>
#include<stdlib.h>
#define GRID 3

int main(){

    char layout[GRID][GRID], ch, p1[50], p2[50];
    int turn=(GRID*GRID), position, i, j;

    printf("\nTIC-TAC-TOE!\n\nRules:\n");
    printf("1. Player 1 can put only 'o'.\n");
    printf("2. Player 2 can put only 'x'.\n");
    printf("Both players need to specify positions where to put their respective character.\n\n");

    printf("Enter Player 1's name:");
    scanf("%s", p1);
    printf("Enter Player 2's name:");
    scanf("%s", p2);

    // initialing layout
    for(i=0; i<GRID; i++){
        for(j=0; j<GRID; j++){
            layout[i][j]=' ';
        }
    }

    // p1 will play when value of turn is even and he will specify position to put a 'o'
    // p2 will play when value of turn is odd and he will specify position to put a 'x'
    while(turn){

        printf("\n");
        
        if(!(turn%2)){
            // p1 turn
            printf("%s, enter position number where you want to put 'o':", p1);
            scanf("%d", &position);
            if((layout[(position-1)/GRID][position-1-(((position-1)/GRID)*GRID)]==' ')&&(position>0)&&(position<=(GRID*GRID))){
                // valid position is input
                layout[(position-1)/GRID][position-1-(((position-1)/GRID)*GRID)]='o';
            }
            else{
                // invalid position is input
                printf("Please try again.\n");
                turn++;
            }
        }

        else{
            // p2 turn
            printf("%s, enter position number where you want to put 'x':", p2);
            scanf("%d", &position);
            if((layout[(position-1)/GRID][position-1-(((position-1)/GRID)*GRID)]==' ')&&(position>0)&&(position<=(GRID*GRID))){
                // valid position is input
                layout[(position-1)/GRID][position-1-(((position-1)/GRID)*GRID)]='x';
            }
            else{
                // invalid position is input
                printf("Please try again.\n");
                turn++;
            }
        }

        turn--;

        printf("The current situation of game is this:\n");
        for(i=0; i<GRID; i++){
            for(j=0; j<GRID; j++){
                printf("%c ", layout[i][j]);
            }
            printf("\n");
        }

        // row check
        for(i=0; i<GRID; i++){
            ch=layout[i][0];

            if(ch==' '){
                continue;
            }

            for(j=1; j<GRID; j++){
                if(layout[i][j]!=ch){
                    break;
                }
            }

            if(j==GRID){
                if(ch=='o'){
                    printf("%s wins!\n\n", p1);
                }
                else{
                    printf("%s wins!\n\n", p2);
                }
                exit(0);
            }
        }

        // column check
        for(i=0; i<GRID; i++){
            ch=layout[0][i];

            if(ch==' '){
                continue;
            }

            for(j=1; j<GRID; j++){
                if(layout[j][i]!=ch){
                    break;
                }
            }

            if(j==GRID){
                if(ch=='o'){
                    printf("%s wins!\n\n", p1);
                }
                else{
                    printf("%s wins!\n\n", p2);
                }
                exit(0);
            }
        }

        // principal diagonal check
        ch=layout[0][0];
        if(ch!=' '){

            for(i=1; i<GRID; i++){
                if(layout[i][i]!=ch){
                    break;
                }
            }

            if(i==GRID){
                if(ch=='o'){
                    printf("%s wins!\n\n", p1);
                }
                else{
                    printf("%s wins!\n\n", p2);
                }
                exit(0);
            }

        }

        // secondary diagonal check
        ch=layout[0][GRID-1];
        if(ch!=' '){

            for(i=1, j=GRID-2; i<GRID; i++, j--){
                if(layout[i][j]!=ch){
                    break;
                }
            }

            if(i==GRID){
                if(ch=='o'){
                    printf("%s wins!\n\n", p1);
                }
                else{
                    printf("%s wins!\n\n", p2);
                }
                exit(0);
            }

        }

    }

    printf("\nBoo! It's a tie!\n\n");

    return 0;
}