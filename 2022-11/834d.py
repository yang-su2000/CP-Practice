# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, m):
    n_ori = n
    c2 = 0
    c5 = 0
    while n % 10 == 0:
        n //= 10
    while n % 2 == 0:
        n //= 2
        c2 += 1
    while n % 5 == 0:
        n //= 5
        c5 += 1
    m_ori = m
    m = 1
    count = 0
    done = False
    while not done:
        done = True
        if c2 and m * 5 <= m_ori:
            m *= 5
            c2 -= 1
            count += 1
            done = False
        if c5 and m * 2 <= m_ori:
            m *= 2
            c5 -= 1
            count += 1
            done = False
    while m * 10 <= m_ori:
        m *= 10
        count += 1
    m *= (m_ori // m)
    return n_ori * m

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, m = [int(i) for i in input().split()]
        print(foo(n, m))