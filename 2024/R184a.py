# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input

if __name__ == '__main__':
    n, m, q = map(int, input().split())
    assert n == 1000
    assert m == 10
    assert q == 950

    ctype = [-1] * n  # denote 1 = real, 0 = fake
    ans = []
    aside = None
    truth = None
    for i in range(0, n, 19):
        j = i + 19
        if j > n:
            for k in range(i, n):
                print(f"? {truth + 1} {k + 1}")
                res = int(input())
                if res == -1:
                    exit(1)
                if res == 0:
                    ctype[k] = ctype[truth]
                else:
                    ctype[k] = 1 - ctype[truth]
            break
        ctype[i] = 1
        c1 = 1
        c0 = 0
        for k in range(i + 1, j):
            print(f"? {k} {k + 1}")
            res = int(input())
            if res == -1:
                exit(1)
            if res == 0:
                ctype[k] = ctype[k - 1]
            else:
                ctype[k] = 1 - ctype[k - 1]
            if ctype[k] == 0:
                c0 += 1
            else:
                c1 += 1
        if (c0 == 10 and c1 == 9) or (c0 == 9 and c1 == 10):
            aside = [i, (c0, c1)]
            continue
        if c0 > c1:
            for k in range(i, j):
                ctype[k] = 1 - ctype[k]
        for k in range(i, j):
            if ctype[k] == 0:
                ans.append(k)
        truth = i
    if aside is not None:
        if ((len(ans) == 0 and aside[1] == (9, 10)) or
                (len(ans) == 1 and aside[1] == (10, 9))):
            for k in range(aside[0], aside[0] + 19):
                ctype[k] = 1 - ctype[k]

    # print(ctype)
    print("! ", end="")
    for i in range(n):
        if ctype[i] == 0:
            m -= 1
            print(i + 1, end=" " if m else "\n")
    assert m == 0
