import Foundation

let MAX = 987654321
var res = 0
var w = [Int]()
var wSz = 0
var d = [Int]()
var visited = [Bool](repeating:false, count: 8)

func perm(_ idx: inout [Int]) {
    if idx.count == d.count {
        for i in 0..<wSz {
            var st = w[i]
            let ed = w[i+wSz-1]
            for j in 0..<d.count {
                st += d[idx[j]]
                if st>=ed {
                    if res > j+1 {res=j+1}
                    break
                }
                var next = i+1
                while w[next]<=st {next+=1}
                st = w[next]
            }
        }
        return
    }
    for i in 0..<d.count {
        if visited[i]==true {continue}
        visited[i] = true
        idx.append(i)
        perm(&idx)
        visited[i] = false
        idx.removeLast()
    }
}

func solution(_ n:Int, _ weak:[Int], _ dist:[Int]) -> Int {
    
    res = MAX
    w = weak
    wSz = weak.count
    
    for i in 0..<wSz {
        w.append(n+w[i])
    }
    
    d = dist
    var idx = [Int]()
    perm(&idx)
    return res==MAX ? -1 : res
}
