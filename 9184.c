#include<stdio.h>

int w(int a, int b, int c){
    int ans;
    if (a<=0 || a<=0 || c<=0)
        return 1;
    
    if (a>20 || b>20 || c>20){
        ans=w(20,20,20);
        return ans;
        }
    
    if (a<b && b<c){
        ans=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
       return ans;
    }
    ans=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    return ans;
}

int main (void){
    int a,b,c,i,j,k;
    int a1=0,b1=0,c1=0;
    int w[21][21][21];
    scanf("%d %d %d",&a,&b,&c);
    
    if (a<=0 || b<=0 || c<=0){
        a=0;
        b=0;
        c=0;
        }   
    if (a>20 || b>20 || c>20){
        a=20;
        b=20;
        c=20;
    }
    for(i=0;i<=20;i++){
        for(j=0;j<21;j++){
            for(k=0;k<21;k++){
                if (a1<=0 || b1<=0 || c1<=0 )
                    w[i][j][k]=1;
                else if (a1<b1 && b1<c1){
                    w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
                    }
                else{
                    w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
                    }
                }
            }   
        }

    printf("%d\n",w[a][b][c]);
}