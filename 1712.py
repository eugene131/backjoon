
def sumaa(a,b,c,num1):

    num1=num1+int(int(a)/int(c))
    print(int(a) % int(c)+(int(b) * int(int(a) / int(c))))
    print(num1)

    if int(int(a)/int(c))>0:
        sumaa((int(a) % int(c) + (int(b) * int(int(a) / int(c)))), b, c, num1)

    else:
        num1=num1+1
        print(num1)

if __name__ == '__main__':
    a,b,c=0,0,0
    i=0
    num1=0#판매량에 따른고정비용과 가변비용의 합
    num2=0#판매량에따른 이익 발생비용
    a,b,c = input("").split()
    print(int(a),b,c)
    if(int(b)>=int(c)):
        print('-1')
    else:
        sumaa(a,b,c,0)
