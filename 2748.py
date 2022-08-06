N=int(input())
f=0
f_1=1
f_2=0
if N==0:
  print(f)
elif N==1:
  print(f_1)
else:
  for i in range(1,N):
    f=f_1+f_2
    f_2=f_1
    f_1=f
  print(f)