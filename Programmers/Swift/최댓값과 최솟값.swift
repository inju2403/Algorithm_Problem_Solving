import Foundation

let INF = 987654321
var mx = -INF
var mn = INF
var res = ""

func solution(_ s:String) -> String {
    
    var ary = s.split(separator:" ").map{Int(String($0))!}
    for i in ary {
        if mx < i {mx=i}
        if mn > i {mn=i}
    }
    res = String(mn) + " " + String(mx)
    
    return res
}
