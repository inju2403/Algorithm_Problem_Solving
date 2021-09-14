import sys
input = sys.stdin.readline

n, m = map(int, input().split())
v = []

def dfs(v, idx):
    if len(v) == m:
        for i in range(m):
            print(v[i], end=" ")
        print()
        return
    for i in range(idx,n+1):
        v.append(i)
        dfs(v,i+1)
        v.pop()

dfs(v,1)
