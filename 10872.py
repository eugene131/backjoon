def factorial(n):
    if(n>1):
        return n*factorial(n-1)
    else:
        return 1

if __name__ == '__main__':
    result = 1
    N = int(input())
    for num in range(1, N + 1, 1):
        result *= num

    print(result)