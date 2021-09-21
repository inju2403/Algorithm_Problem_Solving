import Foundation

let INF = 987654321
var mn = INF

let n = readLine().map{Int($0)!}!
let m = readLine().map{Int($0)!}!

struct Node {
    let w:Int
    let v:Int
}

var dist = [Int](repeating: 0, count: n+1)
var inDegree = [Int](repeating: 0, count: n+1)
var pre = [Int](repeating: 0, count: n+1)
var adj = [[Node]](repeating: [Node](repeating: Node(w:0,v:0), count: 0), count: n+1)

func topology() {
    var q = [Node]()
    q.append(Node(w: 0, v: 1))
    
    while !q.isEmpty {
        let here = q[0].v
        let cost = q[0].w
        q.removeFirst()
        
        for next in adj[here] {
            let there = next.v
            let nextCost = cost + next.w
            if dist[there] < nextCost {
                dist[there] = nextCost
                pre[there] = here
            }
            inDegree[there] -= 1
            if inDegree[there] == 0 && there != 1 {
                q.append(Node(w: dist[there], v: there))
            }
        }
    }
}

for _ in 0..<m {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    let u = input[0], v = input[1], w = input[2]
    adj[u].append(Node(w:w,v:v))
    inDegree[v] += 1
}

topology()

var res = [1]
var before = pre[1]
while before != 1 {
    res.append(before)
    before = pre[before]
}
res.append(1)
res.reverse()
print(dist[1])
for x in res {
    print(x, terminator: " ")
}
