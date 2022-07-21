
square=[[0]*1001 for _ in range(1001)]
dp=[[0]*1001 for _ in range(1001)]

col_num,row_num=list(map(int,input().split()))
for i in range(1,col_num+1):#입력 받기
    row=input()
    a=[]
    for j in range(1,row_num+1):
        square[i][j]=int(row[j-1])
ans=0
for i in range(1,col_num+1):
    for j in range(1,row_num+1):
        if square[i][j]==1:
            dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1        
            if ans<dp[i][j]:
                ans=dp[i][j]
for i in range(0,col_num+1):
    for j in range(0,row_num+1):
        print(dp[i][j],end=" ")
    print()
print(str(ans**2))
