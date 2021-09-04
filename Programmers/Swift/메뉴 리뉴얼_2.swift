import Foundation

var res = [String]()
var hash = [[String:Int]](repeating: [String:Int](), count: 11)

func dfs(_ idx:Int, _ cnt:Int, _ s:[Character], _ cur: inout [Character]) {
    if cnt == cur.count {
        var str = cur.map{String($0)}.joined()
        var val = 0
        if var num = hash[cnt][str] {val=num}
        hash[cnt].updateValue(val+1, forKey: str)
        return
    }
    if idx == s.count {return}
    cur.append(s[idx])
    dfs(idx+1,cnt,s,&cur)
    cur.removeLast()
    dfs(idx+1,cnt,s,&cur)
}

func solution(_ orders:[String], _ course:[Int]) -> [String] {
    
    for i in 0..<orders.count {
        var s = Array(orders[i])
        s.sort()
        for cnt in 0...s.count {
            var cur = [Character]()
            dfs(0,cnt,s,&cur)
        }
    }
    
    for num in course {
        var mx = 0
        for (key, value) in hash[num] {
            mx = max(mx, value)
        }
        if mx <= 1 {continue}
        for (key, value) in hash[num] {
            if mx == value {res.append(key)}
        }
    }
    
    res.sort()
    
    return res
}
