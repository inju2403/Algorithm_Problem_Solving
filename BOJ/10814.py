import sys

input = sys.stdin.readline

class node:
    def __init__(self,age,name,idx):
        self.age = age
        self.name = name
        self.idx = idx

    def __lt__(self, other):
        if self.age != other.age:
            return self.age < other.age
        return self.idx < other.idx

nodes =[]

n = int(input())

for i in range(n):
    age, name = input().split()
    nodes.append(node(int(age),name,i))

nodes.sort()

for x in nodes:
    print(str(x.age) + " " + x.name)
