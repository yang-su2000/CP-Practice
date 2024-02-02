# from functools import reduce

# def factors(n):    
#     return reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))
    
import math
    
def foo(a, b, c, d):
    product = a * b
    for num2 in range(b+1, d+1):
        g = math.gcd(num2, product)
        base = product // g
        if base > c:
            continue
        else:
            num1 = c // base * base
            if a < num1:
                return num1, num2
    return -1, -1
    

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        a, b, c, d = [int(i) for i in input().split()]
        num1, num2 = foo(a, b, c, d)
        print(num1, num2)