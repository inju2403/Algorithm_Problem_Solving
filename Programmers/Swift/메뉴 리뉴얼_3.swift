import Foundation

var res = [String]()
var hash = [String:Int]()

func dfs(_ idx:Int, _ cnt:Int, _ s:[Character], _ cur: inout [Character]) {
    if cnt == cur.count {
        var str = cur.map{String($0)}.joined()
        var val = 0
        if let num = hash[str] {val=num}
        hash.updateValue(val+1, forKey: str)
        return
    }
    if idx == s.count {return}
    cur.append(s[idx])
    dfs(idx+1,cnt,s,&cur)
    cur.removeLast()
    dfs(idx+1,cnt,s,&cur)
}

func solution(_ orders:[String], _ course:[Int]) -> [String] {
    
    for cnt in course {
        hash.removeAll()
        for i in 0..<orders.count {
            var s = Array(orders[i])
            s.sort()
            var cur = [Character]()
            dfs(0,cnt,s,&cur)
        }
        
        var mx = 0
        for (key, value) in hash {
            mx = max(mx, value)
        }
        if mx <= 1 {continue}
        for (key, value) in hash {
            if mx == value {res.append(key)}
        }
    }
    
    res.sort()
    
    return res
}
