a = []
for i in range(0,5):
    a.append(int(input()))

a.sort()
print(sum(a)//5)
print(a[2])
