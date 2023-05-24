s = input()
t = input()
ls = len(s)
lt = len(t)
cur = s[-lt:]
count = 0
for i in range(lt):
    if cur[i] == '?' or t[i] == '?' or cur[i] == t[i]:
        count += 1
print('Yes') if count == lt else print('No')
for i in range(lt):
    add = i
    minus = ls - lt + i
    if s[minus] == '?' or t[i] == '?' or s[minus] == t[i]:
        count -= 1
    if s[add] == '?' or t[i] == '?' or s[add] == t[i]:
        count += 1
    print('Yes') if count == lt else print('No')