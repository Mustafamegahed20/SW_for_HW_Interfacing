#include <stdio.h>
#include <math.h>

int main(){
    
    int x,y,z =0 ;

    printf("Enter three different numbers\n");
    scanf("%i %i %i",&x,&y,&z);
    printf("sum=%i\n",x+y+z);
    printf("Average=%i\n",(x+y+z)/3);
    printf("product=%i\n",(x*y*z));
    printf("smallest=%i\n",(x<y&&x<z)?x:(y<x&&y<z)?y:z);
    printf("Longest=%i\n",(x>y&&x>z)?x:(y>x&&y>z)?y:z);

    return 0 ;
}