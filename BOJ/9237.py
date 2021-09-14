import sys
input = sys.stdin.readline

mx = 0
n = int(input())
v = list(map(int, input().split()))

v.sort(reverse=True)
for i in range(n):
    mx = max(mx, v[i] + i + 2)

print(mx)
