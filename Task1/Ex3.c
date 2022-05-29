#include <stdio.h>
#include <math.h>

int main(){
    
    int m ,h ,s,t =0 ;

    printf("Enter the total time elapsed, in seconds\n");
    scanf("%i",&t);
    printf("--------------------------\n");
    h=t/3600;
    m=(t%3600)/60;
    s=(t%3600)%60;

    printf("time is %i:%i:%i",h,m,s);
    return 0 ;
}