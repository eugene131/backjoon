temp=0

def lolea(D,P,Q):
    if P<Q:
        temp=P
        P=Q
        Q=temp
        temp=0
    if D%P==0 or D%Q==0:
        answer=D
        print(D)
        return
    num=D//P+1
    answer=num*(P)
    for i in range(num-1,-1,-1):
        Div=(D-(i*P))//Q
        mod=(D-(i*P))%Q
        temp=(i*P)+((Div+1)*Q)
        if mod==0:
            answer=D
            break
        if temp==answer:
            break
        answer=min(answer,temp)
    print(answer)

D,P,Q=input().split()
D=int(D)
P=int(P)
Q=int(Q)
lolea(D,P,Q)