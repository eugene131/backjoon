
def check_sqare(i,j):
    global square,row_num,col_num,num
    cunt_row=0#가로 길이
    cunt_col=0#세로 길이
    cunt=0#사용할 기준 길이
    i1=i
    j1=j
    check=True
    
    while True:
        if j1>=row_num:
            break
        if square[i1][j1]==0:#j에서 출발해서 0이 나오면 브레이크
            break
        cunt_row+=1#0이 아니면 가로 길이+1
        #print(j1)
        
        j1+=1#다음 가로 숫자가 1인지 확인하러 이동
    j1=j

    while True:#i에서 출발해서 0이 나오면 브레이크
        if i1>=col_num:
            break
        if square[i1][j1]==0:
            break
        cunt_col+=1#0이 아니면 세로길이+1
        if i1+1>col_num:
            break
        i1+=1#다음 세로 숫자가 1인지 확인하러 이동
    if cunt_row<=cunt_col:
        cunt=cunt_row
    else:
        cunt= cunt_col
    if cunt<=num:
        check=False
        return check, cunt
    for col_i in range(i,i+cunt):
        for row_j in range(j,j+cunt):
            if square[col_i][row_j] == 0:#가로 세로중 짧은 길이 기준으로 검사해서 0인 부분이 하나라도 있으면 flase
                cunt=cunt-1#어차피 하나 아래는 채워지는 거라서
                break

    return check,cunt



col_num,row_num=list(map(int,input().split()))
square=[]
num=0
#print(col_num)
#print(row_num)

for i in range(0,col_num):#입력 받기
    row=input()
    a=[]
    for j in range(0,row_num):
        a.append(int(row[j]))
    square.append(a)


for i in range(0,col_num):#i,j돌면서 확인 하다가
    for j in range(0,row_num):
        if square[i][j]==1:#1이 나오면 거기 사각형이 정사각형인지 확인
            #print(square)
            check=check_sqare(i,j)
            if check[0]==True:#정사각형이면 더 큰값을 check에 넣어줌
                if num<check[1]:
                    num=check[1]
num=num*num
print(num)

