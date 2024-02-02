class Union:
    def __init__(self, size):
        self.ls = [i for i in range(size)]
        self.size = [1] * size
        self.rank = [0] * size
        
    def find(self, i):
        if i != self.ls[i]:
            self.ls[i] = self.find(self.ls[i])
        return self.ls[i]
    
    def link(self, i, j):
        i = self.find(i)
        j = self.find(j)
        if self.size[i] < self.size[j]:
            i, j = j, i
        # i is parent
        if i == j:
            self.rank[i] = 1
        else:
            self.ls[j] = i
            self.size[i] += self.size[j]

n, m = [int(i) for i in input().split()]
U = Union(n)
for _ in range(m):
    a, _, b, _ = [i for i in input().split()]
    a = int(a)-1
    b = int(b)-1
    U.link(a, b)
s = set()
x = 0
y = 0
for i in range(n):
    parent = U.find(i)
    if parent not in s:
        s.add(parent)
        if U.rank[parent]:
            x += 1
        else:
            y += 1
print(x, y)
