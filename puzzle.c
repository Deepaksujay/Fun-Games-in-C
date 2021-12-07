#include <stdio.h>

void Puzzle_4_blocks(int A,int B,int C,int D){  //a,b,c,d=normal space    //A,B,C,D=plates  //denote free space as 1
   while((A!=1)||(B!=2)||(C!=3)||(D!=4)){                                   //2 4
        if(A==1){                                                           //1 3
            printf("Move Plate No %d from Area 3 to Area 1\n",C);                                     
            Puzzle_4_blocks(C,B,A,D);
        }
        if(B==1){
            printf("Move Plate No %d from Area 1 to Area 2\n",A);                                          
            Puzzle_4_blocks(B,A,C,D);
        }
        if(C==1){
            printf("Move Plate No %d from Area 4 to Area 3\n",D);                                        
            Puzzle_4_blocks(A,B,D,C);
        }
        if(D==1){
            printf("Move Plate No %d from Area 2 to Area 4\n",B);                                         
            Puzzle_4_blocks(A,D,C,B);
        }
        break;                                                                 
   }
}

void Puzzle_9_blocks(int a,int b,int c,int d,int e,int f,int g,int h,int i){
    while((a!=1)||(b!=2)||(c!=3)||(d!=4)||(e!=5)||(f!=6)||(g!=7)||(h!=8)||(i!=9)){
       if(a==1){                                                              //1 2 3
            printf("Move Plate No %d from Area 4 to Area 1\n",d);             //4 5 6                        
            Puzzle_9_blocks(d,b,c,a,e,f,g,h,i);                               //7 8 9
        }
        if(b==1){                                                           
            printf("Move Plate No %d from Area 1 to Area 2\n",a);                                     
            Puzzle_9_blocks(b,a,c,d,e,f,g,h,i);
        }
        if(c==1){                                                           
            printf("Move Plate No %d from Area 2 to Area 3\n",b);                                     
            Puzzle_9_blocks(a,c,b,d,e,f,g,h,i);
        }
        if(d==1){                                                           
            printf("Move Plate No %d from Area 5 to Area 4\n",e);                                     
            Puzzle_9_blocks(a,b,c,e,d,f,g,h,i);
        }
        if(e==1){                                                           
            printf("Move Plate No %d from Area 8 to Area 5\n",h);                                     
            Puzzle_9_blocks(a,b,c,d,h,f,g,e,i);
        }
        if(f==1){                                                           
            printf("Move Plate No %d from Area 3 to Area 6\n",c);                                     
            Puzzle_9_blocks(a,b,f,d,e,c,g,h,i);
        }
        if(g==1){                                                           
            printf("Move Plate No %d from Area 8 to Area 7\n",h);                                     
            Puzzle_9_blocks(a,b,c,d,e,f,h,g,i);
        }
        if(h==1){                                                           
            printf("Move Plate No %d from Area 9 to Area 8\n",i);                                     
            Puzzle_9_blocks(a,b,c,d,e,f,g,i,h);
        }
        if(i==1){                                                           
            printf("Move Plate No %d from Area 6 to Area 9\n",f);                                     
            Puzzle_9_blocks(a,b,c,d,e,i,g,h,f);
        }
        
        break;
    }
}

void puzzle_9_somewhatshort(int a,int b,int c,int d,int e,int f,int g,int h,int i){
    while((g!=7)||(h!=8)||(i!=9)){
       if(a==1){                                                              //1 2 3
            printf("Move Plate No %d from Area 4 to Area 1\n",d);             //4 5 6                        
            puzzle_9_somewhatshort(d,b,c,a,e,f,g,h,i);                               //7 8 9
        }
        if(b==1){                                                           
            printf("Move Plate No %d from Area 1 to Area 2\n",a);                                     
            puzzle_9_somewhatshort(b,a,c,d,e,f,g,h,i);
        }
        if(c==1){                                                           
            printf("Move Plate No %d from Area 2 to Area 3\n",b);                                     
            puzzle_9_somewhatshort(a,c,b,d,e,f,g,h,i);
        }
        if(d==1){                                                           
            printf("Move Plate No %d from Area 5 to Area 4\n",e);                                     
            puzzle_9_somewhatshort(a,b,c,e,d,f,g,h,i);
        }
        if(e==1){                                                           
            printf("Move Plate No %d from Area 8 to Area 5\n",h);                                     
            puzzle_9_somewhatshort(a,b,c,d,h,f,g,e,i);
        }
        if(f==1){                                                           
            printf("Move Plate No %d from Area 3 to Area 6\n",c);                                     
            puzzle_9_somewhatshort(a,b,f,d,e,c,g,h,i);
        }
        if(g==1){                                                           
            printf("Move Plate No %d from Area 8 to Area 7\n",h);                                     
            puzzle_9_somewhatshort(a,b,c,d,e,f,h,g,i);
        }
        if(h==1){                                                           
            printf("Move Plate No %d from Area 9 to Area 8\n",i);                                     
            puzzle_9_somewhatshort(a,b,c,d,e,f,g,i,h);
        }
        if(i==1){                                                           
            printf("Move Plate No %d from Area 6 to Area 9\n",f);                                     
            puzzle_9_somewhatshort(a,b,c,d,e,i,g,h,f);
        }
        
        break;
    }
    while((d!=4)||(e!=5)||(f!=6)){
        if(a==1){                                                              //1 2 3
            printf("Move Plate No %d from Area 4 to Area 1\n",d);             //4 5 6                        
            puzzle_9_somewhatshort(d,b,c,a,e,f,g,h,i);                               //7 8 9
        }
        if(b==1){                                                           
            printf("Move Plate No %d from Area 1 to Area 2\n",a);                                     
            puzzle_9_somewhatshort(b,a,c,d,e,f,g,h,i);
        }
        if(c==1){                                                           
            printf("Move Plate No %d from Area 2 to Area 3\n",b);                                     
            puzzle_9_somewhatshort(a,c,b,d,e,f,g,h,i);
        }
        if(d==1){                                                           
            printf("Move Plate No %d from Area 5 to Area 4\n",e);                                     
            puzzle_9_somewhatshort(a,b,c,e,d,f,g,h,i);
        }
        if(e==1){                                                           
            printf("Move Plate No %d from Area 6 to Area 5\n",f);                                     
            puzzle_9_somewhatshort(a,b,c,d,f,e,g,h,i);
        }
        if(f==1){                                                           
            printf("Move Plate No %d from Area 3 to Area 6\n",c);                                     
            puzzle_9_somewhatshort(a,b,f,d,e,c,g,h,i);
        }
    }
    while((a!=1)||(b!=2)||(c!=3)){
        if(b==1){                                                           
            printf("Move Plate No %d from Area 1 to Area 2\n",a);                                     
            puzzle_9_somewhatshort(b,a,c,d,e,f,g,h,i);
        }
        if(c==1){                                                           
            printf("Move Plate No %d from Area 2 to Area 3\n",b);                                     
            puzzle_9_somewhatshort(a,c,b,d,e,f,g,h,i);
        }
    }
}



int main(){

    //Puzzle_4_blocks(3,1,4,2);
    // int a[9],j;
    // for(j=0;j<9;j++){
    //     printf("Enter plate No in the area of %d here:",j+1);
    //     scanf("%d",&a[j]);
    //     printf("\n");
    // }
    // Puzzle_9_blocks(a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
    puzzle_9_somewhatshort(8,2,7,1,9,3,4,5,6);
    

    return 0;
}