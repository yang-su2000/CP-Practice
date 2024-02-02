def foo(n, k, s):
    if n == 1 or k == 1:
        return True
    # print(n, k, s, ':')
    s = s[::-1] # decreasing
    pre = s[0] - s[1]
    # print(pre, end=' ')
    for i in range(2, k):
        cur = s[i-1] - s[i]
        if cur > pre:
            return False
        pre = cur
        # print(pre, end=' ')
    remain = pre * (n-k+1)
    # print(':', remain)
    return s[-1] <= remain

t = int(input())
for _ in range(t):
    n, k = [int(i) for i in input().split()]
    s = [int(i) for i in input().split()]
    print("Yes" if foo(n, k, s) else "No")