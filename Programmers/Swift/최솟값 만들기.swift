import Foundation

func solution(_ A:[Int], _ B:[Int]) -> Int
{
    var ans = 0
    
    var a = A
    var b = B
    
    a.sort()
    b.sort(by: >)
    
    for i in 0..<a.count {
        ans += a[i]*b[i]
    }

    return ans
}
