import Foundation

let MAX = 1010

var a = [[Int]](repeating: [Int](repeating: 0, count: MAX), count: MAX)
var res = [Int]()
var num = 1
var y = -1
var x = 0
var ori = 0

func solution(_ N:Int) -> [Int] {
    
    var n = N
    
    while n>0 {
        for i in 0..<n {
            y+=1
            a[y][x] = num
            num+=1
        }
        n-=1
        if n==0 {break}
        for i in 0..<n {
            x+=1
            a[y][x] = num
            num+=1
        }
        n-=1
        if n==0 {break}
        for i in 0..<n {
            y-=1
            x-=1
            a[y][x] = num
            num+=1
        }
        n-=1
    }
    
    n = N
    for y in 0..<n {
        for x in 0..<y+1 {
            res.append(a[y][x])
        }
    }
    
    return res
}
