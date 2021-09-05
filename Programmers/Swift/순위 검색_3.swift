import Foundation

var hash = [String : [Int]]()
var sorted = [String : Bool]()
var res = [Int]()

func dfs(_ idx:Int, _ cnt:Int, _ v:[String], _ ary:inout [Int]) {
    if ary.count == cnt {
        var chk = [Bool](repeating:false, count:4)
        for i in ary {chk[i]=true}
        var str = ""
        let score = Int(v[4])!
        for i in 0..<4 {
            if chk[i] == true {str += v[i]}
            else {str += "-"}
        }
        str = String(str)
        if hash[str] == nil {
            hash[str] = [Int]()
        }
        hash[str]!.append(score)
        return
    }
    if(idx==4) {return}
    ary.append(idx)
    dfs(idx+1, cnt, v, &ary)
    ary.removeLast()
    dfs(idx+1, cnt, v, &ary)
}

func solution(_ info:[String], _ query:[String]) -> [Int] {
    
    for str in info {
        var v = str.split(separator:" ").map{String($0)}
        let score = Int(v[4])!
        var ary = [Int]()
        for cnt in 0...4 {
            dfs(0,cnt,v,&ary)
        }
    }
    
    for str in query {
        var v = str.split(separator:" ").filter{$0 != "and"}
        
        let str = String(v[0]+v[1]+v[2]+v[3])
        if hash[str] == nil {
            res.append(0)
            continue
        }
        if sorted[str] == nil {
            hash[str]!.sort()
            sorted[str] = true
        }
        let num = Int(v[4])!
        
        //binary search
        var mx = -1
        var l = 0
        var r = hash[str]!.count-1
        while l <= r {
            let mid = (l+r)/2
            if hash[str]![mid] < num {
                mx = max(mx, mid)
                l = mid+1
            } else {
                r = mid-1
            }
        }
        res.append(hash[str]!.count-mx-1)
    }
    return res
}
