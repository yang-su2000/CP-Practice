def foo(n, ls):
    ls.sort()
    # print(ls)
    ans = float('inf')
    for i in range(1, n-1):
        diff1 = ls[i] - ls[i-1]
        diff2 = ls[i+1] - ls[i]
        ans = min(ans, diff1 + diff2)
    return ans

t = int(input())
for _ in range(t):
    n = int(input())
    ls = [int(i) for i in input().split()]
    print(foo(n, ls))
