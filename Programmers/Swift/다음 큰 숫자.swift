import Foundation

var cnt = 0
var res = 0

func solution(_ N:Int) -> Int {
    var n = N
    while n>0 {
        cnt += n%2
        n/=2
    }
    
    var res = N+1
    while res<1000005 {
        var c = 0
        var k = res
        while k>0 {
            c += k%2
            k/=2
        }
        if c==cnt {return res}
        res+=1
    }
    
    return res
}
