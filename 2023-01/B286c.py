# python sample.py < input.txt

if __name__ == '__main__':
    N, A, B = [int(i) for i in input().split()]
    s = input()
    s_ = s[N // 2:] + s[:N // 2]
    s1 = s[:N // 2]
    s2 = s[N // 2 + N % 2:][::-1]
    ans = float('inf')
    a, b = 0, 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            b += 1
    ans = min(ans, a * A + b * B)
    # print(s1, s2, a, b, ans)
    for i in range(N):
        a, b = i + 1, 0
        s2 = s1[0] + s2[:-1]
        s1 = s1[1:] + s_[i]
        for j in range(len(s1)):
            if s1[j] != s2[j]:
                b += 1
        ans = min(ans, a * A + b * B)
        # print(s1, s2, a, b, ans)
    print(ans)