#include<stdio.h>


int main()
{
    int n,i,d_i1,d_i2,d,temp;
    scanf("%d",&n);
    d=3;
    d_i1=2;
    d_i2=1;
    for(i=3;i<n;i++){
        d_i2=d_i1;
        d_i1=d;
        d=(d_i1+d_i2)%15746;
        
    }
    if(n==1){
        printf("1\n");
    }
    else if(n==2){
        printf("2\n");
    }
    else if(n==3){
        printf("3\n");
    }
    else
        printf("%d\n",d);
    return 0;
}

