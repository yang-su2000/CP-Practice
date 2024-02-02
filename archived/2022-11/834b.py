# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(m, s, ls):
    cmax = max(ls)
    st = set([i for i in range(1, cmax + 1)])
    for i in ls:
        if i in st:
            st.remove(i)
    s -= sum(st)
    if s < 0:
        return False
    cur = cmax + 1
    while s > 0:
        s -= cur
        cur += 1
    return s == 0

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        m, s = [int(i) for i in input().split()]
        ls = [int(i) for i in input().split()]
        if foo(m, s, ls):
            print('Yes')
        else:
            print('No')