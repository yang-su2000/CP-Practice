# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, h, ls):
    ls.sort()
    ret = 0
    h_ori = h
    for ps in [[2, 2, 3], [2, 3, 2], [3, 2, 2]]:
        h = h_ori
        p = 0
        i = 0
        ans = 0
        while i < n:
            while h <= ls[i]:
                if p < len(ps):
                    h *= ps[p]
                    p += 1
                else:
                    break
            if h <= ls[i]:
                break
            h += ls[i] // 2
            i += 1
            ans += 1
        ret = max(ret, ans)
    return ret

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, h = [int(i) for i in input().split()]
        ls = [int(i) for i in input().split()]
        print(foo(n, h, ls))