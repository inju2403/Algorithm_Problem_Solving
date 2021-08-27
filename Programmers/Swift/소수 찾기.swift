import Foundation

let MAX = 10000001
var p: [Bool] = [Bool](repeating: true, count: MAX)
var visited: [Bool] = [Bool](repeating: false, count: MAX)
var res = 0
var n = 0
var v = [Int]()
var dic = [Int : Bool]()

func getPrime() {
    p[0]=false
    p[1]=false
    let n = Int(sqrt(Double(MAX)))
    for i in 2...n {
        var j = i+i
        while j<MAX {
            p[j] = false
            j+=i
        }
    }
}

func dfs(_ idx: Int, _ sz: Int, _ v: inout [Int], _ num: [Int]) {
    if v.count == sz {
        let k = Int(v.map{String($0)}.joined())!
        if p[k]==true && dic[k]==nil {
            dic[k]=true
            res+=1
        }
        return
    }
    for i in 0..<n {
        if visited[i]==true {continue}
        v.append(num[i])
        visited[i]=true
        dfs(i, sz, &v, num)
        v.removeLast()
        visited[i]=false
    }
}

func solution(_ numbers:String) -> Int {
    n = numbers.count
    getPrime()
    
    var num = Array(numbers).map{Int(String($0))!}
    for i in 1...num.count {
        dfs(0,i,&v,num)
    }
    
    return res
}
