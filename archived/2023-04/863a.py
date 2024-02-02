# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, d = [i for i in input().split()]
        n = int(n)
        s = input()
        done = False
        for i in range(n):
            if s[i] >= d:
                continue
            else:
                done = True
                print(s[:i] + d + s[i:])
                break
        if not done:
            print(s + d)