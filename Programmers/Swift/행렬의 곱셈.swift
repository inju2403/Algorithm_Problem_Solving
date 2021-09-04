import Foundation

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    
    var res = [[Int]](repeating: [Int](repeating:0, count: arr2[0].count), count: arr1.count)
    
    for y in 0..<res.count {
        for x in 0..<res[0].count {
            for i in 0..<arr1[0].count {
                res[y][x] += arr1[y][i]*arr2[i][x]
            }
        }
    }
    
    return res
}
