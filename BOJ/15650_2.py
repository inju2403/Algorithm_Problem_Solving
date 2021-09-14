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
    if idx > n:
        return
    v.append(idx)
    dfs(v,idx+1)
    v.pop()
    dfs(v,idx+1)

dfs(v,1)
