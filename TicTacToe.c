#include <stdio.h>

char Tic[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; //Initialised Array

void display(){ //Displays the array
    printf("\n    |%c|%c|%c|\n",Tic[0][0],Tic[0][1],Tic[0][2]);
    printf("    |%c|%c|%c|\n",Tic[1][0],Tic[1][1],Tic[1][2]);
    printf("    |%c|%c|%c|\n\n",Tic[2][0],Tic[2][1],Tic[2][2]);
}

void displaySample(){ //Displays the positions array
    printf("Here is the positions for your reference in the format (i,j)\n");
    printf("\n    |(1,1)|(1,2)|(1,3)|\n");
    printf("    |(2,1)|(2,2)|(2,3)|\n");
    printf("    |(3,1)|(3,2)|(3,3)|\n\n");
}

int checkvalid(int i,int j,char l){ //i=row  j=coloumn  l=X or O
    if((i>=1)&&(i<=3)){             //return 1 if inputs or valid or 0
        if((j>=1)&&(j<=3)){
            if((l=='X') || (l=='O')){
                return 1;
            }
            else {
                printf("Enter valid Character\n");
            }
        }
        else{
            printf("Enter valid column\n");
        }
    }
    else{
            printf("Enter valid row\n");
    }
    return 0;
}

int checkEmpty(int i,int j){    //checks whether already position has X or O
    if ((Tic[i-1][j-1]=='X') || (Tic[i-1][j-1]=='O')){
        printf("Already the position %d-%d has %c \nTry other position\n",i,j,Tic[i-1][j-1]);
        return 0;
    } 
    return 1;
}

int checkwin(){   //returns 0 if player won or else 1
    int i,j,k=0;
    for (i=0;i<3;i++){           //checks all rows
        if ((Tic[i][0]=='X') || (Tic[i][0]=='O')){
            for (j=0;j<3;j++){
                if (Tic[i][j] == Tic[i][0]){
                    k++;
                }
            }
            if (k==3){
                printf("player with character %c won in the row %d\n",Tic[i][0],i+1);
                return 0;
            }
            k=0;
        }
    }
    //check Columns 
    for (j=0;j<3;j++){           //checks all Columns 
        if ((Tic[0][j]=='X') || (Tic[0][j]=='O')){
            for (i=0;i<3;i++){
                if (Tic[i][j] == Tic[0][j]){
                    k++;
                }
            }
            if (k==3){
                printf("player with character %c won in the column %d\n",Tic[0][j],j+1);
                return 0;
            }
            k=0;
        }
    }
    //check downward diagnol
    if ((Tic[0][0]=='X') || (Tic[0][0]=='O')){
        for (i=0;i<3;i++){
            if (Tic[i][i]==Tic[0][0]){
                k++;
            }
        }
        if (k==3){
            printf("player with character %c won in the downward diagnol\n",Tic[0][0]);
            return 0;
        } 
        k=0;
    }
    //check upward diagnol
    if ((Tic[0][2]=='X') || (Tic[0][2]=='O')){
        for (i=0;i<3;i++){
            if (Tic[i][2-i]==Tic[0][2]){
                k++;
            }
        }
        if (k==3){
            printf("player with character %c won in the upward diagnol\n",Tic[0][2]);
            return 0;
        } 
        k=0;
    }
    //check tied
    for(i=0;i<3;i++){
        for (j=0;j<3;j++){
            if ((Tic[i][j]=='X') || (Tic[i][j]=='O')){
                k++;
            }
        }
    }
    if (k==9){
        printf("Match Tied between both the players\n");
        return 0;
    }
    return 1;
}

void insertX (){   //used for inserting X
    if (checkwin()){
        int i,j;
        char l = 'X';
        printf("Your placement of '%c':",l);
        scanf("%d-%d",&i,&j);
        if (checkvalid(i,j,l)+checkEmpty(i,j)==2){
            Tic[i-1][j-1]=l;
        }
        else{
            insertX();
        }
    }
}

void insertO (){   //used for inserting O
    if (checkwin()){
        int i,j;
        char l = 'O';
        printf("Your placement of '%c':",l);
        scanf("%d-%d",&i,&j);
        if (checkvalid(i,j,l)+checkEmpty(i,j)==2){
            Tic[i-1][j-1]=l;
        }
        else{
            insertO();
        }
    }
}

void insert(){    //inserts X and O one after the other
    insertX();
    display();
    insertO();
    display();
}

void play(){
    printf("Welcome to TIC-TAC-TOE\n");
    displaySample();
    printf("Enter your placement in format row-column\n");
    while (checkwin()){
        insert();
    }
}

int main(){

    play();

    return 0;
}