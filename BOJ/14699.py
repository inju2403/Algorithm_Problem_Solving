import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

n, m = map(int, input().split())

adj = [[] for _ in range(n + 1)]
cache = [-1 for _ in range(n + 1)]

h = list(map(int, input().split()))
h.insert(0, -1)

for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)


def dp(cur):
    if cache[cur] != -1:
        return cache[cur]
    cache[cur] = 0
    for next in adj[cur]:
        if h[next] > h[cur]:
            cache[cur] = max(cache[cur], dp(next))
    cache[cur] += 1
    return cache[cur]


for i in range(1, n + 1):
    print(dp(i))
