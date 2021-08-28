import Foundation

let INF = 987654321
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
                var next = wSz-1
                var l = i+1
                var r = wSz-1
                while l<=r {
                    let mid = (l+r)/2
                    if w[mid] > st {
                        if next > mid {next=mid}
                        r = mid-1
                    }
                    else {l = mid+1}
                }
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
    
    res = INF
    w = weak
    wSz = weak.count
    
    for i in 0..<wSz {
        w.append(n+w[i])
    }
    
    d = dist
    var idx = [Int]()
    perm(&idx)
    return res==INF ? -1 : res
}
