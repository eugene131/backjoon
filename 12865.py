#배낭 문제
N,K=list(map(int,input().split()))
W=[0]
V=[0]
for i in range(0,N):
  a,b=list(map(int,input().split()))
  W.append(a)
  V.append(b)
dp=[]
use_s_num=0
for i in range(0,K+1):
  dp.append(0)
for i in range(0,N+1):
  use_s_num=0
  for j in range(0,K+1):
    if W[i]<=j:
      if use_s_num==0:
        dp[j] = max((dp[j-W[i]]+V[i]),dp[j],dp[j-1])
        if dp[j]==dp[j-W[i]]+V[i] | j==V[i]:
          use_s_num=-1
      else:
        dp[j]=max(dp[j],dp[j-1])

  
  print(dp)
print(max(dp))



        


    



