# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict
from string import ascii_lowercase as alc

def foo(n, t):
    t = list(t)
    d = {}
    ans = []
    keys, vals = 1, 1
    s = [i for i in alc]

    def is_closed(i, cur):
        nonlocal keys, vals, d
        keys |= (1 << ord(i))
        vals |= (1 << ord(cur))
        d[i] = cur
        ret = (len(d) < 26 and keys == vals)
        del d[i]
        keys &= ~(1 << ord(i))
        vals &= ~(1 << ord(cur))
        return ret

    def rec(ti):
        nonlocal d, t, ans, s, keys, vals
        if ti == len(t):
            return True
        if t[ti] in d:
            ans.append(d[t[ti]])
            if rec(ti + 1):
                return True
            ans.pop()
            return False
        for c in s:
            if vals & (1 << ord(c)) or c == t[ti] or is_closed(t[ti], c):
                continue
            else:
                d[t[ti]] = c
                keys |= (1 << ord(t[ti]))
                vals |= (1 << ord(c))
                ans.append(c)
                if rec(ti + 1):
                    return True
                del d[t[ti]]
                keys &= ~(1 << ord(t[ti]))
                vals &= ~(1 << ord(c))
                ans.pop()
        return False
    
    rec(0)
     
    return ''.join(ans)

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        t = input()
        print(foo(n, t))