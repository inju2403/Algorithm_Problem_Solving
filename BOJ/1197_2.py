class node:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w
    def __lt__(self, arg): # 정렬 기준
        return self.w < arg.w

parent = [i for i in range(10005)]

def getParent(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = getParent(parent[x])
        return parent[x]

def merge(a, b):
    a = getParent(a)
    b = getParent(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

ary = []
n, m = map(int, input().split())

while m>0:
    m-=1
    u,v,w = map(int, input().split())
    ary.append(node(u,v,w))

ary.sort()
res = 0
for x in ary:
    if getParent(x.u) != getParent(x.v):
      res += x.w
      merge(x.u, x.v)
print(res)
