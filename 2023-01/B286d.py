# python sample.py < input.txt

if __name__ == '__main__':
    N, X = [int(i) for i in input().split()]
    ls = []
    for _ in range(N):
        a, b = [int(i) for i in input().split()]
        ls.extend([a] * b)
    ls.sort()
    # print(ls)
    dp = [False] * (X + 1)
    dp[0] = True
    for coin in ls:
        dp2 = [False] * (X + 1)
        for i in range(coin, X + 1):
            if dp[i - coin]:
                dp2[i] = True
        for i in range(coin, X + 1):
            if dp2[i]:
                dp[i] = True
        # print(dp)
    # print(dp)
    print('Yes' if dp[X] else 'No')