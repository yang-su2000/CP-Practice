# import math, heapq, bisect, itertools, functools

# python sample.py < input

def bisect_right(ls, val):
    l, r = 0, len(ls)
    while l < r:
        mid = (l + r) // 2
        if ls[mid][0] <= val:
            l = mid + 1
        else:
            r = mid
    return l

if __name__ == '__main__':
    n = int(input())
    A = [int(i) for i in input().split()]
    pre = []
    time = 0
    for i in range(1, n-1, 2):
        a, b = A[i], A[i+1]
        time += b - a
        pre.append((a, b, time))
    # print(pre)
    q = int(input())
    for _ in range(q):
        l, r = [int(i) for i in input().split()]
        pl = bisect_right(pre, l)
        pr = bisect_right(pre, r)
        # print(l, r, "->", pl, pr)
        ans = 0
        if pr >= 1:
            if pl >= 1:
                ans += pre[pr-1][2] - pre[pl-1][2]
                # print(1, ans)
                ans += max(0, pre[pl-1][1] - l)
                # print(2, ans)
            else:
                ans += pre[pr-1][2]
                # print(2, ans)
            ans -= max(0, pre[pr-1][1] - r)
            # print(3, ans)
        print(ans)
