import sys
sys.setrecursionlimit(10000)

def w(a,b,c):
    if a<=0 or a<=0 or c<=0:
        return 1
    if a>20 or b>20 or c>20:
        return w(20,20,20)
    if a<b and b<c:
        return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)
    return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)

while True:
    a,b,c=input().split()
    a=int(a)
    b=int(b)
    c=int(c)
    # w=0
    # a1,b1,c1=1,1,1
    # if a>20 or b>20 or c>20:
    #     a=20
    #     b=20
    #     c=20

    # if a==-a and b==-a and c==-a:
    #     break
    # if a<=0 or b<=0 or c<=0:
    #     w=1
    # for i in range(0,a):
            

    print(w(a,b,c))
