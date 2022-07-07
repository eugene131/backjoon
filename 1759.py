answer=[]
def check_a(li):
    cha_cunt = 0
    chb_cunt = 0
    for i in range(l):
        if answer[i]=='a' or answer[i]=='e' or answer[i]=='i' or answer[i]=='o' or answer[i]=='u':
            cha_cunt=cha_cunt+1
        else:
            chb_cunt=chb_cunt+1
    return cha_cunt,chb_cunt
def brtf(depth):
    d.sort()
    if depth ==l:
        a,b=check_a(answer)
        if a>=1 and b>=2:
            for i in range(l):
                print(answer[i],end="")
            print()
        return
    for i in range(k):
        if len(answer)==0:
            answer.append(d[i])
            brtf(depth+1)
            answer.pop()
        else:
            if answer[len(answer)-1]<d[i]:
                answer.append(d[i])
                brtf(depth+1)
                answer.pop()


l,k=input().split()
l=int(l)
k=int(k)
d=list(input().split())
brtf(0)