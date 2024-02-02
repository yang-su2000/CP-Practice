s = list(input())
i = 0
while i < len(s) - 1:
    s[i], s[i+1] = s[i+1], s[i]
    i += 2
print(''.join(s))