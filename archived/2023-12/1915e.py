t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    s = set([0])
    ans = False
    odd = True
    sum = 0
    for x in a:
        if odd: sum += x
        else: sum -= x
        if sum in s:
            ans = True
            break
        s.add(sum)
        odd = not odd
    print("YES" if ans else "NO")
