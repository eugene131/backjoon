#17136

def ch_paper(starti,startj,n):#n*n색종이 붙이기, 붙은 곳은 -1
    global a,cunt
    ch_num=0
    if starti+n>10 or startj+n>10:
        return 0
    for i in range(starti,starti+n):
        for j in range(startj,startj+n):
            if a[i][j]!=1:
                return 0
    if ch_num==0:
        for i in range(starti, starti + n):
            for j in range(startj, startj + n):
                a[i][j]=-1
  #      print("use:",n)
  #      for i in range(10):
   #         for j in range(10):
  #              print("%3d" %(a[i][j]),end="")
   #         print()
 #       print()
    return 1

def re_paper(starti,startj,n):#색종이 리셋
    global a,cunt
    #if starti+n>10 or startj+n>10:
    #    return
    for i in range(starti, starti + n):
        for j in range(startj, startj + n):
            a[i][j] = 1
   # print("re:", n)
  #  for i in range(10):
  #      for j in range(10):
   #         print("%3d" % (a[i][j]), end="")
   #     print()
   # print()

    return
ycnt=0
def search_paper(i,j):#백트레킹 위한 탐색
    global a, cunt, num, ycnt
    ycnt+=1
  #  print(ycnt,"st: i:", i, "j:", j, "num:", num, "paper_num[1]", paper_num[1], "paper_num[2]", paper_num[2],
   #       "paper_num[3]", paper_num[3], "paper_num[4]", paper_num[4], "paper_num[5]", paper_num[5])


    if i==10:
        num=min(cunt,num)
        return
    if j==10:
        search_paper(i+1,0)
        return
    if a[i][j]!=1:
        search_paper(i,j+1)
        return
    elif a[i][j]==1:
        for k in range(5,0,-1):
            if paper_num[k] <= 0:
                continue
            if ch_paper(i,j,k)==0:
                continue
            else:

                cunt += 1
                paper_num[k] -= 1
                search_paper(i,j+k-1)

               # print("re: i:", i, "j:", j, "num:", num, "paper_num[1]", paper_num[1], "paper_num[2]", paper_num[2],
                #      "paper_num[3]", paper_num[3], "paper_num[4]", paper_num[4], "paper_num[5]", paper_num[5])
                re_paper(i,j,k)
                cunt -= 1
                paper_num[k]+=1


    return
paper_num=[]
paper_num.append(0)
for i in range(5):
    paper_num.append(5)
cunt=0
a=[]#10*10배열 담을 리스트
num=1000
for i in range(10):#10X10배열 담았음
    a.append(list(map(int,input().split())))
search_paper(0,0)
if num==1000:
    print('-1')
else:
    print(num)