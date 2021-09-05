import Foundation

let ch = ["A","E","I","O","U"]
var res = 0
var v = [String]()

func dfs(_ cnt:Int, _ cur: inout [Int]) {
    if cnt == cur.count {
        var str = ""
        for x in cur {
            str += ch[x]
        }
        v.append(str)
        return
    }
    for i in 0..<5 {
        cur.append(i)
        dfs(cnt, &cur)
        cur.removeLast()
    }
}

func solution(_ word:String) -> Int {
    
    for cnt in 1...5 {
        var tmp = [Int]()
        dfs(cnt, &tmp)
    }
    v.sort()
    
    for i in 0..<v.count {
        if v[i] == word {
            res = i+1
            break
        }
    }
    
    return res
}
