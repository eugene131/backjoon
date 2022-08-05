#배낭 문제
N,K=list(map(int,input().split()))
W=[0]
V=[0]
for i in range(0,N):
  a,b=list(map(int,input().split()))
  W.append(a)
  V.append(b)
use=[]
dp=[]
for i in range(0,2):
  a=[]
  for j in range(0,K+1):
    a.append(0)
  dp.append(a)

for i in range(1,N+1):
  temp_i=i%2
  for j in range(1,K+1):
    if temp_i==0:
      if W[i]<=j: 
        dp[temp_i][j] = max((dp[temp_i+1][j-W[i]]+V[i]),dp[temp_i+1][j])
      else:
        dp[temp_i][j]=dp[temp_i+1][j]    
    else:
      if W[i]<=j: 
        dp[temp_i][j] = max((dp[temp_i-1][j-W[i]]+V[i]),dp[temp_i-1][j])
      else:
        dp[temp_i][j]=dp[temp_i-1][j]      
#  print(dp)
if N%2==0:
  print(dp[0][K])
else:
  print(dp[1][K])
#print(dp[N][K])