import Foundation

struct node {
    let x: Int
    let y: Int
    let a: Int
}

var v = [node]()
var hash = [String:Bool]() // x|y|a 로 해싱

func judge(_ e:[Int]) {
    var chk = true
    let str = String(e[0]) + "|" + String(e[1]) + "|" + String(e[2])
    
    if(e[3]==1) {
        
        let x = e[0]
        let y = e[1]
        let a = e[2]
        
        if a == 0 { // 기둥
            let s1 = String(x-1) + "|" + String(y) + "|" + String(a+1)
            let s2 = String(x) + "|" + String(y) + "|" + String(a+1)
            let s3 = String(x) + "|" + String(y-1) + "|" + String(a)
            
            if y != 0
            && (hash[s1] == nil && hash[s2] == nil)
            && hash[s3] == nil {
                chk = false
            }
        }
        else { // 보
            let s1 = String(x) + "|" + String(y-1) + "|" + String(a-1)
            let s2 = String(x+1) + "|" + String(y-1) + "|" + String(a-1)
            let s3 = String(x-1) + "|" + String(y) + "|" + String(a)
            let s4 = String(x+1) + "|" + String(y) + "|" + String(a)
            
            if (hash[s1] == nil && hash[s2] == nil)
            && (hash[s3] == nil || hash[s4] == nil) {
                chk = false
            }
        }
        if chk == true {
            hash.updateValue(true, forKey:str)
        }
    }
    else {
        hash.removeValue(forKey: str)

        for (key, value) in hash {
            let c = key.split(separator: "|")
            let x = Int(c[0])!
            let y = Int(c[1])!
            let a = Int(c[2])!

            if a == 0 { // 기둥
                if y == 0 {continue} // 바닥 위

                let s1 = String(x-1) + "|" + String(y) + "|" + String(a+1)
                let s2 = String(x) + "|" + String(y) + "|" + String(a+1)
                if hash[s1] != nil || hash[s2] != nil {continue} // 보 위

                let s3 = String(x) + "|" + String(y-1) + "|" + String(a)
                if hash[s3] != nil {continue} // 다른 기둥 위

                chk = false
                break
            }
            else { // 보
                var s1 = String(x) + "|" + String(y-1) + "|" + String(a-1)
                var s2 = String(x+1) + "|" + String(y-1) + "|" + String(a-1)
                if hash[s1] != nil || hash[s2] != nil {continue} // 기둥 위

                s1 = String(x-1) + "|" + String(y) + "|" + String(a)
                s2 = String(x+1) + "|" + String(y) + "|" + String(a)
                if hash[s1] != nil && hash[s2] != nil {continue} // 앙옆 보

                chk = false
                break
            }
        }
        if chk == false {
            hash.updateValue(true, forKey:str)
        }
    }
}


func solution(_ n:Int, _ build_frame:[[Int]]) -> [[Int]] {
    
    for e in build_frame {
        judge(e)
    }
    
    for (key, value) in hash {
        let c = key.split(separator: "|")
        let x = Int(c[0])!
        let y = Int(c[1])!
        let a = Int(c[2])!
        let p = node(x: x, y: y, a: a)
        v.append(p)
    }
        
    v.sort {
        if $0.x != $1.x {
            return $0.x < $1.x
        } else if $0.y != $1.y {
            return $0.y < $1.y
        } else {
            return $0.a < $1.a
        }
    }
    
    var ret = [[Int]]()
    for i in v {
        let p = [i.x, i.y, i.a]
        ret.append(p)
    }
    
    return ret
}
