import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6) # 최대 재귀 깊이를 1,000,000 정도로 크게 설정

n, s, d = map(int, input().split())

adj = [[] for _ in range(n + 1)]
visited = [False for _ in range(n + 1)]
children = [0 for _ in range(n + 1)]


def setChildren(src):
    chk = True
    for x in adj[src]:
        if not visited[x]:
            visited[x] = True
            chk = False
            children[src] = max(children[src], setChildren(x))
    if chk:
        return 0
    children[src] += 1
    return children[src]


def dfs(src):
    ret = 0
    for x in adj[src]:
        if not visited[x]:
            visited[x] = True
            if children[x] >= d:
                ret += dfs(x)
    return ret + 1


for _ in range(n - 1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

visited[s] = True
setChildren(s)
visited = [False for _ in range(n + 1)]
visited[s] = True
print((dfs(s)-1)*2)
