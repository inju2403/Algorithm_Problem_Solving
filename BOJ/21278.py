import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

INF = 987654321

n, m = map(int, input().split())

adj = [[] for _ in range(n + 1)]
dist = []
mn = INF
a = 0
b = 0
total = [-1]

for i in range(n + 1):
    dist.append([INF for _ in range(n + 1)])
for i in range(1, n + 1):
    dist[i][i] = 0

for _ in range(m):
    a, b = map(int, input().split())
    dist[a][b] = 1
    dist[b][a] = 1

def floyd():
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

floyd()

for i in range(1,n+1):
    for j in range(i+1,n+1):
        if i==j: continue
        sum = 0
        for k in range(1,n+1):
            sum += min(dist[i][k], dist[j][k])
        if mn > sum:
            mn = sum
            a = i
            b = j

print(str(a) + " " + str(b) + " " + str(2*mn))
