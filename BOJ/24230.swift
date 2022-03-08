let n = Int(readLine()!)!
var resultColor = readLine()!
    .split(separator: " ")
    .map{ Int($0)! }
resultColor.insert(0, at: 0)
var adj = [[Int]](repeating: [], count: n+1)
var res = 0
for _ in 1..<n {
    let connect = readLine()!
        .split(separator: " ")
        .map{ Int($0)! }
    adj[connect[0]].append(connect[1])
    adj[connect[1]].append(connect[0])
}

func dfs(_ current: Int, _ parentColor: Int, _ parent: Int) {
    var currentColor = parentColor
    if currentColor != resultColor[current] {
        res += 1
        currentColor = resultColor[current]
    }
    for child in adj[current] {
        if child == parent { continue }
        dfs(child, currentColor, current)
    }
}

dfs(1, 0, 0)
print(res)
