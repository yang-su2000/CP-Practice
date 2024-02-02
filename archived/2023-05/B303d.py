# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input.txt

if __name__ == '__main__':
    x, y, z = [int(i) for i in input().split()] # x - press, y - shift press, z - change state
    s = input()
    a, A = 0, z
    for c in s:
        if c == 'a':
            a, A = min(a + x, A + z + x), min(A + y, a + z + y)
        elif c == 'A':
            a, A = min(a + y, A + z + y), min(A + x, a + z + x)
        # print(a, A)
    print(min(a, A))
            