let MAX = 1000001
let MOD = 1234567

func solution(_ n:Int) -> Int {
    var a = [Int](repeating: 0, count: MAX)
    a[1]=1
    for i in 2...n {
        a[i]=(a[i-1]+a[i-2])%MOD
    }
    return a[n]
}
