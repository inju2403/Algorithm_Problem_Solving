import Foundation

var input = readLine()!.split(separator: " ").map{Int(String($0))!}
let n = input[0], m = input[1]

let h = [0] + readLine()!.split(separator: " ").map{Int(String($0))!}
var cache = [Int](repeating: -1, count: n+1)
var adj = [[Int]](repeating: [Int](repeating: 0, count: 0), count: n+1)

for _ in 0..<m {
    input = readLine()!.split(separator: " ").map{Int(String($0))!}
    let a = input[0], b = input[1]
    adj[a].append(b)
    adj[b].append(a)
}

func dp(_ cur:Int) -> Int {
    if cache[cur] != -1 {return cache[cur]}
    
    cache[cur] = 0
    for next in adj[cur] {
        if h[next] > h[cur] {
            cache[cur] = max(cache[cur], dp(next))
        }
    }
    cache[cur] += 1
    return cache[cur]
}

for i in 1...n {
    print(dp(i))
}
