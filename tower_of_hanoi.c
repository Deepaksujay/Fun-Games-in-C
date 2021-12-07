#include <stdio.h>
#include <math.h>
void func(int n, char l, char m,char r){

    if (n>0){
        func(n-1,l,r,m);
       printf("disc %d from %c to %c \n",n,l,r);
       func(n-1,m,l,r);
    }
    
}
int main(){
    
    int n;
    printf("Enter no of discs:");
    scanf("%d",&n);
    char l='l',m='m',r='r';
    func(n,l,r,m);




 return 0;
}