import Foundation

let input = readLine()!.split(separator: " ").map{Int(String($0))!}

let V = input[0]
let E = input[1]
var parent = [Int]()

for i in 0...V {
    parent.append(i)
}

struct node {
    var u: Int
    var v: Int
    var w: Int
}

var v = [node]()
var res = 0

func getParent(_ x:Int) -> Int {
    if x == parent[x] {return x}
    parent[x] = getParent(parent[x])
    return parent[x]
}

func merge(_ a:Int, _ b:Int) {
    let q = getParent(a)
    let w = getParent(b)
    if q < w {
        parent[w] = q
    }
    else {
        parent[q] = w
    }
}

for iter in 0..<E {
    let p = readLine()!.split(separator: " ").map{Int(String($0))!}
    v.append(node(u:p[0], v:p[1], w:p[2]))
}

v.sort {
    $0.w < $1.w
}

for k in v {
    if getParent(k.u) != getParent(k.v) {
        res += k.w
        merge(k.v, k.u)
    }
}

print(res)
