# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

def foo(n, bs):
    ls = [0] * (n + 1)
    for i, b in enumerate(bs):
        ls[b] = i
    i = n
    bi = 0
    st = []
    ans = []
    while bi < len(bs):
        b = bs[bi]
        if st:
            ans.append(st.pop())
            ans.append(b)
        else:
            while ls[i]:
                i -= 1
            while i >= 1 and ls[i] == 0:
                st.append(i)
                i -= 1
            ans.append(st.pop())
            ans.append(b)
        bi += 1
    return ans        

# python sample.py < input.txt

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        bs = [int(i) for i in input().split()]
        space = False
        for i in foo(n, bs):
            if space:
                print('', end=' ')
            else:
                space = True
            print(i, end='')
        print()