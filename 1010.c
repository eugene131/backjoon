#include<stdio.h>

int facto(int n, int count_num);
int nCr(int n,int r);

int main()
{
    int i,T,N[1000],M[1000],ans[1000];
    int cunt[1000]={0};
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d %d",&N[i],&M[i]);
    }
    //printf("facto test: %d\n",facto(5,3));
    for(i=0;i<T;i++){
        if (N[i]>15)
            ans[i]=nCr(M[i],M[i]-N[i]);
        else    
            ans[i]=nCr(M[i],N[i]);
    }
    for(i=0;i<T;i++){
        printf("%d\n",ans[i]);
    }


    return 0;
}

int nCr(int n, int r){
    int i,j,k,k2,num=1;
    int num1=1;
    int num2=1;
    int ans;
    int dp1[31],dp2[31];

    for(k=0,i=n,j=r;j>0;k++,i--,j--){
        dp1[k]=i;
        dp2[k]=j;
    }
     
    for(i=0,k=r;k>0;k--,i++){
        for(j=0,k2=r;k2>0;k2--,j++){
            if(dp2[j]!=1 && dp1[i] % dp2[j]==0){
                dp1[i]=dp1[i]/dp2[j];
                dp2[j]=1;
            }
        }   
    }
   //printf("dp1: ");
    for(i=0;i<r;i++){
        num1=num1*dp1[i];
        //printf("%d ",dp1[i]);
        }
        //printf("\n");
    //printf("dp2: ");
    for(i=0;i<r;i++){
        num2=num2*dp2[i];
       // printf("%d ",dp2[i]);
        }
       // printf("\n");
    ans=num1/num2;
    return ans;
}


int facto(int n, int count_num){
    int i,j,num=1;
    for(i=n;count_num>0;i--,count_num--){
        num=num*i;
    }    
    return num;
}