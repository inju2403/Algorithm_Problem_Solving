import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

INF = 987654321

n = int(input())
m = int(input())

adj = [[] for _ in range(n + 1)]
pre = [0] * (n + 1)
dist = [0] * (n + 1)
inDegree = [0] * (n + 1)

for _ in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((w, v))
    inDegree[v] += 1

q = [[0, 1]]

while q:
    here = q[0][1]
    cost = q[0][0]
    q.pop(0)

    for next in adj[here]:
        there = next[1]
        nextCost = cost + next[0]
        if dist[there] < nextCost:
            dist[there] = nextCost
            pre[there] = here
        inDegree[there] -= 1
        if inDegree[there] == 0 and there != 1:
            q.append((dist[there], there))

print(dist[1])
res = [1]
before = pre[1]
while before != 1:
    res.append(before)
    before = pre[before]
res.append(1)

res.reverse()
for x in res:
    print(x, end=" ")
