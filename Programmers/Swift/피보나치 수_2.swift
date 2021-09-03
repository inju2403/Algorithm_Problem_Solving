let MAX = 1000001
let MOD = 1234567

var cache = [Int](repeating: -1, count: MAX)

func f(_ x:Int) -> Int {
    if x==0 {return 0}
    if x==1 {return 1}
    
    if cache[x] != -1 {return cache[x]}
    
    cache[x] = (f(x-1)+f(x-2))%MOD
    return cache[x]
}

func solution(_ n:Int) -> Int {
    return f(n)
}
