import sys

input = sys.stdin.readline

n, m = map(int, input().split())
mp = [input() for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
global res
res = 1


def isRange(y, x):
    return 0 <= y < n and 0 <= x < m


def bfs():
    q = [[0, 0, 0]]
    visited[0][0] = True
    while q:
        cy = q[0][0]
        cx = q[0][1]
        ccnt = q[0][2]
        q.pop(0)

        if cy == n - 1 and cx == m - 1:
            global res
            res = ccnt+1
            break

        for dir in range(4):
            ny = cy + dy[dir]
            nx = cx + dx[dir]
            if isRange(ny, nx) and visited[ny][nx] == False and mp[ny][nx]=='1':
                visited[ny][nx] = True
                q.append([ny, nx, ccnt + 1])


bfs()
print(res)
