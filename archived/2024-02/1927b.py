t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    d = {}
    cur = 'a'
    ans = []
    for freq in a:
        if freq == 0:
            ans.append(cur)
            d[cur] = 0
            cur = chr(ord(cur) + 1)
        else:
            for c in d.keys():
                if d[c] + 1 == freq:
                    ans.append(c)
                    d[c] += 1
                    break
    print(''.join(ans))