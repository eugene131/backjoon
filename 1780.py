cu=0
cum1=0
cup1=0
def paper(n,pap,startx,starty):
    num=pap[startx][starty]
    cunt=0
    global cu,cum1,cup1
    for i in range(startx,startx+n):
        for j in range(starty,starty+n):
            if num!=pap[i][j]:
                cunt = -1
                break
                break
    if cunt!=-1 or n==1:
        if num==0:
            cu = cu+1
        elif num==-1:
            cum1=cum1+1
        else:
            cup1=cup1+1
    if n>=3 and cunt == -1:
        paper(int(n/3),pap,startx,starty)
        paper(int(n/3),pap,startx+int(n/3),starty)
        paper(int(n/3), pap, startx+int(n*2/3), starty)

        paper(int(n / 3), pap, startx, starty+int(n/3))
        paper(int(n / 3), pap, startx+int(n/3), starty+int(n/3))
        paper(int(n / 3), pap, startx + int(n*2 / 3), starty+int(n/3))

        paper(int(n / 3), pap, startx, starty+int(2*n/3))
        paper(int(n / 3), pap, startx + int(n / 3), starty+int(2*n/3))
        paper(int(n / 3), pap, startx + int(n*2 / 3), starty+int(2*n/3))



n=int(input())
pa=[]
for i in range(0,n):
    pa.append(list(map(int,input().split())))
paper(n,pa,0,0)
print(cum1)
print(cu)
print(cup1)