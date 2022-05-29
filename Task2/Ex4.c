
#include <stdio.h>
#include <math.h>
int main(){

    float x;
    int n;
    float result = 1.0f;
    int fact=1;

    printf("Enter the Exponent");
    scanf("%f",&x);
    printf("Enter number of iterations");
    scanf("%d",&n);
    for (int i = 1; i < n; i++)
    {
        fact*=i;
        result=result+(pow(x,i)/fact);
    }

    printf("%f",result);
    return 0 ;
}