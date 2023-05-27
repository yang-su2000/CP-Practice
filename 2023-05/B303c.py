# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input.txt

if __name__ == '__main__':
    n, m, h, k = [int(i) for i in input().split()]
    s = input()
    st = set()
    for _ in range(m):
        x, y = [int(i) for i in input().split()]
        st.add((x, y))
    x, y = 0, 0
    ans = 'Yes'
    for i in range(n):
        # print(h, x, y, st, s[i])
        c = s[i]
        if s[i] == 'R':
            x += 1
        elif s[i] == 'L':
            x -= 1
        elif s[i] == 'U':
            y += 1
        elif s[i] == 'D':
            y -= 1
        h -= 1
        if h < 0:
            ans = 'No'
            break
        if h < k and (x, y) in st:
            st.remove((x, y))
            h = k
    print(ans)
