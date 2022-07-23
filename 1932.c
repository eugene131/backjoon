#include<stdio.h>

int main(void)
{   
    int a[500][500],n,i,j,dp[500][500];
    int ans=0;
    for(i=0;i<500;i++)
        for(j=0;j<500;j++){
            a[i][j]=-1;
            dp[i][j]=0;
            }

    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        for(j=0;j<i+1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dp[0][0]=a[0][0];
    for(i=1;i<n;i++){
        dp[i][0]=a[i][0]+dp[i-1][0];
    }
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            if (dp[i-1][j]>dp[i-1][j-1])
                dp[i][j]=a[i][j]+dp[i-1][j];
            else
                dp[i][j]=a[i][j]+dp[i-1][j-1];
        }
    }
    //printf("dp list: ");
    for(j=0;j<n;j++)
    //    printf("%d ",dp[n-1][j]);
    //printf("\n");
    for(j=0;j<n;j++){

        if (dp[n-1][j]>ans){
            ans=dp[n-1][j];
      //      printf("change dp: %d\n",ans);
            }
    }
    printf("%d\n",ans);
    return 0;
}