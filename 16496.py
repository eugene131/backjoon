N=int(input())#N받아주고
arr=list(map(int,input().split()))#다음줄에 오는 input들 받아줌
sum=0
for i in range(0,N):#만약 원소의 함들이 0이면 모든 원소가 0
    sum=sum+arr[i]
def sort1():
    for i in range(0,N):
        for j in range(i,N):
            if First_Num[i]>First_Num[j]:
                temp=First_Num[i]
                temp1=arr[i]
                First_Num[i]=First_Num[j]
                arr[i]=arr[j]
                First_Num[j]=temp
                arr[j]=temp1

arr.sort()#배열 정렬
First_Num=[]
cunt=1
if sum==0:#그래서 0 출력
    print('0')
else:
    for i in range(0,N):
        temp=str(arr[i])#문자열로 First_Num에 넣을거임
        while True:
            if len(temp)<=len(str(arr[N-1])):#가장 자릿수 많은 숫자의 길이가 더 길면
                temp=temp+str(arr[i])#temp다음에 똑같은 숫자인 temp추가해줌(늘려줌)
            else: break
        First_Num.append(temp)#늘려준 배열 First_Num에 넣어줌
    sort1()
    for i in range(0,N):
        print(arr[N-1-i],end="")

#배열을 늘려주는 이유는 자릿수의 끝에서 비교했을 때 더 큰 숫자가 앞으로 오는것이 합계가 커지기 때문