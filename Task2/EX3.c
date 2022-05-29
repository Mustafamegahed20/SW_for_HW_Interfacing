
#include <stdio.h>

int main(){

    int n = 0;

    scanf("%d",&n);


    if(n<=1)return n;

    long int current=1,previous=0,x=0;

    for (size_t i = 1; i <=n; i++)
    {
        if(i == 1) {
            printf("%d ",previous);
            continue;
        }

        if(i == 2) {
            printf("%d ",current);
            continue;
        }


        x=current;
        current += previous;
        previous=x;
        printf("%d ",current);


    }
    return 0 ;
}