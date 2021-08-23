import Foundation

let input = readLine()!.split(separator: " ").map{Int(String($0))!}

var v = [Int]()
func dfs(_ idx: Int ) {
    if v.count == input[1] {
        print(v.map{String($0)}.joined(separator: " "))
    }
    for i in idx..<input[0]+1 {
        v.append(i)
        dfs(i+1)
        v.removeLast()
    }
}
dfs(1)
