import Foundation

var hash = [String : [Int]]()
var sorted = [String : Bool]()
var res = [Int]()

func solution(_ info:[String], _ query:[String]) -> [Int] {
    
    for str in info {
        var v = str.split(separator:" ").map{String($0)}
        let score = Int(v[4])!
        
        var str = String(v[0]+v[1]+v[2]+v[3])
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        
        str = String("-"+v[1]+v[2]+v[3])
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        str = String(v[0]+"-"+v[2]+v[3])
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        str = String(v[0]+v[1]+"-"+v[3])
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        str = String(v[0]+v[1]+v[2]+"-")
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        
        str = String("-"+"-"+v[2]+v[3])
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        str = String("-"+v[1]+"-"+v[3])
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        str = String("-"+v[1]+v[2]+"-")
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        str = String(v[0]+"-"+"-"+v[3])
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        str = String(v[0]+"-"+v[2]+"-")
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        str = String(v[0]+v[1]+"-"+"-")
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        
        str = String("-"+"-"+"-"+v[3])
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        str = String("-"+"-"+v[2]+"-")
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        str = String("-"+v[1]+"-"+"-")
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        str = String(v[0]+"-"+"-"+"-")
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
        
        str = String("----")
        if hash[str] == nil {hash[str] = [Int]()}
        hash[str]!.append(score)
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
