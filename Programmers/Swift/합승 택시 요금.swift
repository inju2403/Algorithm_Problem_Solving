import Foundation

let INF = 3123456789
let MAX = 201

var dist = [[Int]](repeating:[Int](repeating:INF, count: MAX), count: MAX)
var res = INF

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    for i in 1...n {
        dist[i][i] = 0
    }
    for x in fares {
        dist[x[0]][x[1]]=x[2]
        dist[x[1]][x[0]]=x[2]
    }
    for k in 1...n {
        for i in 1...n {
            for j in 1...n {
                if dist[i][j] > dist[i][k]+dist[k][j] {
                    dist[i][j] = dist[i][k]+dist[k][j]
                }
            }
        }
    }
    
    for i in 1...n {
        res = min(res,dist[s][i]+dist[a][i]+dist[b][i])
    }
    
    return res
}
