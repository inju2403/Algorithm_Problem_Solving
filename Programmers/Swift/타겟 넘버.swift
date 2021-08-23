import Foundation

var res = 0

func dfs(_ n:[Int], _ t:Int, _ idx:Int, _ sum: Int) {
    if idx == n.count {
        if sum == t {
            res += 1
        }
        return
    }
    dfs(n, t, idx+1, sum+n[idx])
    dfs(n, t, idx+1, sum-n[idx])
}

func solution(_ numbers:[Int], _ target:Int) -> Int {
    dfs(numbers, target, 0, 0)
    return res
}
