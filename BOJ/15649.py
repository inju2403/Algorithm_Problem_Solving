import sys
input = sys.stdin.readline

n, m = map(int, input().split())
v = []

visited = {}

def dfs(v, cnt):
    if len(v) == cnt:
        for i in range(cnt):
            print(v[i], end=" ")
        print()
        return
    for i in range(1,n+1):
        if i in visited:
            continue
        visited[i] = 1
        v.append(i)
        dfs(v,cnt)
        del visited[i]
        v.pop()

dfs(v,m)
