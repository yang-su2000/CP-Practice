# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

d = {'Y': 'e', 'e': 's', 's': 'Y'}

def foo(s: str):
    i = 0
    while i < len(s):
        if s[i] not in d:
            return False
        if i < len(s) - 1:
            if d[s[i]] != s[i+1]:
                return False
        i += 1
    return True
            

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        if foo(s):
            print('Yes')
        else:
            print('No')