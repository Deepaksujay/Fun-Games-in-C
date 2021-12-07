#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int UpperLimit = 1000, LowerLimit = 0;

int RandomGenerator(){    //generates our random number
    return (rand()%(UpperLimit-LowerLimit+1))+LowerLimit;
}

int checkwin(int answer, int input){  //checks whether the guessed no is wrong or not
    if (answer == input){
        return 0;
    }
    return 1;
}

void insert(int *l){        //takes input for the guessing number;
    printf("Enter your guess here:");
    scanf("%d",l);
}

void progress(int input, int answer){     //delivers hints and relation between the input and answer
    if (answer == input){
        printf("Congrats you Guessed the number, It is '%d'\n",answer);
    }
    else if (answer > input){
        if (answer - input <= 10){
            printf("So close, little more\n");
        }
        else if (answer - input <= 100){
            printf("Somewhat closer, still need to guess little bigger\n");
        }
        else if (answer - input > 100){
            printf("way too low\n");
        }
    }
    else if (answer < input){
        if (input - answer <= 10){
            printf("So close, little less\n");
        }
        else if (input - answer <= 100){
            printf("Somewhat closer, still need to guess little lower\n");
        }
        else if (input - answer > 100){
            printf("way too high\n");
        }
    }
}

int play_single(){       //have a complete game for the single player including various above commands
    srand(time(0));
    int Number = RandomGenerator(), input = 1001, count=0;
    //printf("random number is %d\n",Number);
    printf("A random value between 0 to 1000 is assigned, start guessing\n");
    while (checkwin(Number,input)){
        insert(&input);
        progress(input,Number);
        count++;
    }
    printf("Your score is %d\n",count);
    return count;
}

void winner(int arr[][2], int length){    //If a group is playing then the function arr[i][2]
    int delta = 1, i, temp;               //takes scores in arr[i][0] and player no in arr[i][1]
    while (delta){                        //This function arranges the array arr[i][2] into
        delta = 0;                        // increasing order also changing the player numbers
        for (i=1;i<length;i++){           //accordingly, so that scorecard can be shown easily
            if (arr[i][0]<arr[i-1][0]){
                temp = arr[i][0];
                arr[i][0] = arr[i-1][0];
                arr[i-1][0] = temp;
                temp = arr[i][1];
                arr[i][1] = arr[i-1][1];
                arr[i-1][1] = temp;
                delta++;
            }
        }
    }
}

void Display_winners(int arr[][2],int length){  //Displays the scorecard
    int i;                                  //Nothing but displays rearranged score arrays
    printf("Here is the list of the score card\n");
    for (i=0;i<length;i++){
        printf("Player.No:%d    No.Of.Guesses:%d    Rank:%d\n",arr[i][1],arr[i][0],i+1);
    }
}

void playgroup(){  //this function helps taking no of players and runs programme that many times
    int i,noof,score[noof][2],l;    //also collects their score and dislpays in proper order
    printf("Welcome to the Random Number Game\n");   //simply the only function we call
    printf("Here a secret random number between 0 to 1000 is assigned to you\n");
    printf("All you have to do is keep on guessing till you guess it correctly\n");
    printf("The one with the least guesses wins \n");
    printf("Please enter the no of players playing the game:");
    scanf("%d",&noof);
    for (i=1;i<=noof;i++){
        printf("Welcome palyer no %d\n",i);
        score[i-1][0] = play_single();
        score[i-1][1] = i;
        if (i == 2){
            l = score[i-1][0];
        }
    }
    score[1][0] = l;
    winner(score,noof);
    Display_winners(score,noof);
}

int main(){
    
    playgroup();
    // int arr[4][2] = {{10,1},{8,2},{6,3},{8,4}};
    // winner(arr,4);
    // Display_winners(arr,4);

    return 0;
}