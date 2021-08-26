import Foundation

func solution(_ number:String, _ K:Int) -> String {
    var k = K
    var cnt = 0
    
    var numbers = Array(number).map{Int(String($0))!}
    var res: [Int] = []
    
    for i in 0..<numbers.count {
        if  res.isEmpty == true {
            res.append(numbers[i])
        } else {
            while res.isEmpty == false
            && res.last! < numbers[i]
            && k>0 {
                res.removeLast()
                k-=1
            }
            
            if k==0 {
                for j in i..<numbers.count {
                    res.append(numbers[j])
                }
                break
            }
            res.append(numbers[i])
        }
    }
    while k>0 {
        res.removeLast()
        k-=1
    }
    return res.map{String($0)}.joined()
}
