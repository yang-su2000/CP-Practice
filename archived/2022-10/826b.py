# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n):
    if n == 1 or n == 3:
        return [-1]
    ans = [i for i in range(1, n + 1)]
    ans.reverse()
    if n % 2 == 0:
        return ans
    ans[n // 2:] = ans[n // 2:][::-1]
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        for i in foo(n):
            print(i, end=' ')
        print()