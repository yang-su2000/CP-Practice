# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict
# from sortedcollections import SortedList, SortedSet, SortedDict
import math

def foo(n, ls):
    target = min(ls)
    ans = 0
    for a in ls:
        l = 1
        r = math.ceil(a / target)
        # print(l, r, end=' ')
        while l < r:
            mid = (l + r) // 2
            if math.ceil(a / mid) >= 2 * target:
                l = mid + 1
            else:
                r = mid
        # print(l)
        ans += l - 1
    return ans

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ls = [int(i) for i in input().split()]
        print(foo(n, ls))