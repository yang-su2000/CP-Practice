# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict
import math

def lcm(a, b):
    return abs(a * b) // math.gcd(a, b)

def foo(n, a):
    b = [1] * (n + 1)
    for i in range(n):
        b[i] = lcm(b[i], a[i])
        b[i+1] = a[i]
    for i in range(n):
        if a[i] != math.gcd(b[i], b[i+1]):
            return False
    return True

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [int(i) for i in input().split()]
        if foo(n, a):
            print('YES')
        else:
            print('NO')