qu=[]

class Node:
    def __init__ (self, data, link=None):
        self.data = data
        self.search=0#방문X=0 방문O=-1
        self.link = link

head = []
chlist=[]
DFchlist=[]
stck=[]
def PrintList(head):
    while True:
        if head:
            print(head.data,end=" ")
            head=head.link
        else : break
    print()

def Linkappend(root,Node):
    if root.link:
        beforeHead=root
        head=root.link
        while True:
            if head.link:
                if head.data<Node.data:
                    head=head.link
                    beforeHead=beforeHead.link
                else:
                    Node.link=beforeHead.link
                    beforeHead.link=Node
                    break
            else :
                if head.data>Node.data:
                    beforeHead.link=Node
                    Node.link=head
                    break
                else:
                    head.link=Node
                    break
    else: root.link=Node

def BFS(start):
    qu.append(start)
    chlist[start - 1] = -1
    while True:
        if qu:
            qpop=qu.pop(0)
            print(qpop,end=" ")
            temp=head[qpop-1].link
            for i in range(0,N):
                if temp:
                    if chlist[temp.data-1]==0:
                        qu.append(temp.data)
                        chlist[temp.data-1]=-1
                        temp=temp.link
                    else: temp=temp.link
                else: break
        else: break



def DFS( v):
    global head
    temp=head[v-1]
    DFchlist[v-1]=True
    print(v, end=' ')
    while True:
        if temp:
            i=temp.data
            temp=temp.link
            if not DFchlist[i-1]:
                DFS(i)
        else: break





N,M,V=list(map(int,input().split()))

for i in range(0,N):
    newNode=Node(i+1)
    head.append(newNode)
    chlist.append(0)
    DFchlist.append(0)
for i in range(0,M):
    V1,V2=input().split()
    V1=int(V1)
    V2=int(V2)

    newNode = Node(V2)
    Linkappend(head[V1-1],newNode)

    newNode = Node(V1)
    Linkappend(head[V2 - 1], newNode)
#for i in range(0, N):
#    PrintList(head[i])

DFS(V)
print()
BFS(V)

