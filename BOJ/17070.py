import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

INF = 987654321

n = int(input())
mp = []
d = [[[-1 for _ in range(3)] for _ in range(n)] for _ in range(n)]  # d[y][x][dir]: y,x - 끝점  dir - 0~2  오른쪽 아래 대각선
d[0][1][0] = 1

for _ in range(n):
    k = list(map(int, input().split()))
    mp.append(k)


def isRange(y, x):
    return 0 <= y < n and 0 <= x < n


def dp(y, x, dir):
    if mp[y][x] == 1:
        return 0
    if d[y][x][dir] != -1:
        return d[y][x][dir]

    d[y][x][dir] = 0
    if dir == 0:
        if isRange(y, x - 2) and mp[y][x - 2] + mp[y][x - 1] == 0:
            d[y][x][dir] += dp(y, x - 1, 0)
        if isRange(y - 1, x - 2) and mp[y][x - 2] + mp[y][x - 1] + mp[y - 1][x - 1] + mp[y - 1][x - 2] == 0:
            d[y][x][dir] += dp(y, x - 1, 2)

    elif dir == 1:
        if isRange(y - 2, x) and mp[y - 1][x] + mp[y - 2][x] == 0:
            d[y][x][dir] += dp(y - 1, x, 1)
        if isRange(y - 2, x - 1) and mp[y - 1][x] + mp[y - 1][x - 1] + mp[y - 2][x] + mp[y - 2][x - 1] == 0:
            d[y][x][dir] += dp(y - 1, x, 2)
    else:
        if mp[y][x] + mp[y - 1][x] + mp[y][x - 1] > 0:
            return 0
        if isRange(y - 1, x - 2) and mp[y - 1][x - 2] + mp[y - 1][x - 1] == 0:
            d[y][x][dir] += dp(y - 1, x - 1, 0)
        if isRange(y - 2, x - 1) and mp[y - 1][x - 1] + mp[y - 2][x - 1] == 0:
            d[y][x][dir] += dp(y - 1, x - 1, 1)
        if isRange(y - 2, x - 2) and mp[y - 1][x - 1] + mp[y - 2][x - 1] + mp[y - 1][x - 2] + mp[y - 2][x - 2] == 0:
            d[y][x][dir] += dp(y - 1, x - 1, 2)

    return d[y][x][dir]


res = dp(n - 1, n - 1, 0) + dp(n - 1, n - 1, 1) + dp(n - 1, n - 1, 2)
print(res)
