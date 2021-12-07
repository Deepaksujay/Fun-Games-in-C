#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int sticks(remaining,logical) {
   int picked;
   printf("Why don't you pick up first?\n");
   printf("Total no of sticke in game:%d\n",remaining);
   printf("Maximum no of sticks that can be picked at a time:%d\n",logical);
   while(remaining>1){
      printf("          Your picks:");
      scanf("%d",&picked);
      if (picked<=logical&&picked>0)
      {
      printf("Sticks still left:%d\n",remaining-picked);
      printf("          My picks:%d \n",logical+1-picked);
      remaining=remaining-logical-1;
      printf("Sticks still left:%d\n",remaining);
      }

      else {
         printf("          pick validly\n");
      }
   }
   printf("    HEHE YOU LOSTTTTT\n    Now take that single stick and leave \n");
}

int sticks_start(){
   int n;
   printf("Shall us play a game?\n");
   printf("PERSON WHO PICKS THE LAST STICK LOSES THE GAME \n");
   printf("How many sticks you want to play with?\n");
   printf("1.19 \n2.21 \n3.25 \n4.26 \n5.29 \n");
   printf("Enter your choice here:");
   scanf("%d",&n);
   switch (n)
   {
      case 1:
         sticks(19,5);
         break;
      case 2:
         sticks(21,4);
         break;
      case 3:
         sticks(25,5);
         break;
      case 4:
         sticks(26,4);
         break;
      case 5:
         sticks(29,6);
         break;
      default:
         printf("Please do enter valid option\n");
         break; 
   }
}

int main(){
   
   
  sticks_start();
   
  return 0;
}