#include <stdio.h>

int main(){

     int year,rem,rem2,leaps,non_leaps,value,date,i,month,numb=0,main,main2,real,sum;
    printf("Please enter date (DD-MM-YYYY):");
    scanf("%d-%d-%d",&date,&month,&year);
    rem=year%400;    
    rem2=rem/100;    //cslculates no of 100's in entered year
    if(year%4==0){                     //calculates no of leap years till that year
        if (year%100==0&&year%400!=0){
            leaps=(rem/4)+1-rem2;
        }
        else{
            leaps=(rem/4)-rem2;
        }
    }
    else{
        leaps=(rem/4)+1-rem2;
    }
    
    non_leaps=rem-leaps;
    value=leaps*2+non_leaps;
    main=value%7;
    
    if (year%4==0){
        if (year%100==0&&year%400!=0){
            leaps=365;
        }
        else{
            leaps=366;
        }
    }
    else{
        leaps=365;
    }
    if (leaps ==365){
        int sum[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};      //find days in non leap year
        for (i=0;i<month;i++){
            numb=numb+sum[i];
        }
    }
    if (leaps ==366){                                              //find days in leap year
        int sum[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
        for (i=0;i<month;i++){
            numb=numb+sum[i];
        }
    }
    numb=numb+date;
    main2=numb%7;                      
    real=(main+main2-1)%7;        //remainder of odd days + th day o fthe year with 7 and then minus 1 gives day
    char c[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    printf("The date %d-%d-%d is %s \n",date,month,year,c[real]);








    return 0;
}