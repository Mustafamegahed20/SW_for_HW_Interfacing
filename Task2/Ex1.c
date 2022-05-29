// Write a program to perform a generic rotate right and rotate left expression using bit masking.
// The code shall ask the user to enter an 8 bit number x, number of rotate cycles n and rotate
// option o. The software shall print the rotate value of x, n times based on the value of o.

#include <stdio.h>
#define INT_BITS 8

int main(){

    unsigned char x;
    int n,o;
    printf("Enter Number");
    scanf("%d",&x);
    printf("Enter Number of rotate cycles");
    scanf("%d",&n);
    printf("Enter 1 (Right rotate) Or 0 (left rotate ) ");
    scanf("%d",&o);

    if (n>=8)
    {
        n=n%INT_BITS;
    }
    unsigned char result;
    if(o==1){
        result=(x >> n) | (x << (INT_BITS - n));
        printf("%d",result);
    }else{
        result=(x << n)|(x >> (INT_BITS - n));
        printf("%d",result);
    }
    

    return 0 ;
}