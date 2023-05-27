# import math, heapq, bisect, itertools, functools
# from collections import deque, Counter, defaultdict, OrderedDict

# python sample.py < input.txt

if __name__ == '__main__':
    n = int(input())
    s = input()
    t = input()
    ans = True
    for i in range(n):
        if s[i] == t[i] or (s[i] == '1' and t[i] == 'l') or (s[i] == 'l' and t[i] == '1') or (s[i] == '0' and t[i] == 'o') or (s[i] == 'o' and t[i] == '0'):
            continue
        else:
            ans = False
    print('Yes' if ans else 'No')
