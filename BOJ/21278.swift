import Foundation

let INF = 987654321
var mn = INF

var input = readLine()!.split(separator: " ").map{Int(String($0))!}
let n = input[0], m = input[1]

var dist = [[Int]](repeating: [Int](repeating: INF, count: n+1), count: n+1)

for _ in 0..<m {
    input = readLine()!.split(separator: " ").map{Int(String($0))!}
    let a = input[0], b = input[1]
    dist[a][b]=1
    dist[b][a]=1
}

for i in 1...n {
    dist[i][i] = 0
}

var a = 0, b = 0

for k in 1...n {
    for i in 1...n {
        for j in 1...n {
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
        }
    }
}

for i in 1...n-1 {
    for j in i+1...n {
        var sum = 0
        for k in 1...n {
            sum += min(dist[i][k] ,dist[j][k])
        }
        if mn > sum {
            mn = sum
            a = i
            b = j
        }
    }
}

print(a,b,2*mn,separator: " ")
