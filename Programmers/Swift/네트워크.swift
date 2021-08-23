import Foundation

let MAX = 205

var res = 0
var visited = [Bool](repeating: false, count: MAX)
var adj = [[Int]](repeating: Array(repeating: 0, count: 0), count: MAX)

func dfs(_ cur: Int) {
    for next in adj[cur] {
        if visited[next] == true {
            continue
        }
        visited[next]=true
        dfs(next)
    }
}

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    
    for y in 0..<computers.count {
        for x in 0..<computers[0].count {
            if y==x {
                continue
            }
            if computers[y][x]==1 {
                adj[y].append(x)
                adj[x].append(y)
            }
        }
     }
    
    for i in 0..<n {
        if visited[i]==false {
            visited[i]=true
            dfs(i)
            res+=1
        }
    }
    
    return res
}
