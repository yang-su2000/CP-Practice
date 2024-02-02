class Trie:
    def __init__(self):
        self.d = {}
        self.tail = 0
        self.count = 0
        
    def find(self, s, i):
        if i == len(s):
            if self.count > 1:
                return i
            return i - 1
        c = s[i]
        if self.count <= 1 or c not in self.d:
            return i - 1
        return self.d[c].find(s, i+1)
    
    def add(self, s, i):
        if i == len(s):
            self.tail += 1
            return
        c = s[i]
        if c not in self.d:
            self.d[c] = Trie()
        self.d[c].add(s, i+1)
        
    def trace(self):
        self.count = self.tail
        for v in self.d.values():
            self.count += v.trace()
        return self.count
        
    def debug(self):
        if not self.d:
            return '[.]'
        ret = '['
        for k, v in self.d.items():
            ret += k + str(self.count) + v.debug()
        ret += ']'
        return ret
        
n = int(input())
ls = []
T = Trie()
for _ in range(n):
    s = input()
    T.add(s, 0)
    ls.append(s)
T.trace()
# print(T.debug())
for s in ls:
    print(T.find(s, 0))