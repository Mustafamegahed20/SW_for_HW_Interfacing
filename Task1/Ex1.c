#include <stdio.h>
#include <math.h>

int main(){
    
    float v , u ,a ,s,t =0 ;

    printf("Enter intial velocity\n");
    scanf("%f",&u);
    printf("--------------------------\n");
    printf("Enter acceleration of an object\n");
    scanf("%f",&a);
    printf("--------------------------\n");
    printf("Enter time that has elapsed\n");
    scanf("%f",&t);
    
    v= u + a*t;    
    s= u*t+ 0.5*a*t*t;
    printf("final velocity= %f\ndistance traversed= %f",v,s);


 

    return 0 ;
}