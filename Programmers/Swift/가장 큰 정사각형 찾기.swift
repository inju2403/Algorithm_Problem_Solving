import Foundation

var mx = 0
var mp = [[Int]]()

func solution(_ board:[[Int]]) -> Int {
    
    let ySz = board.count
    let xSz = board[0].count
    mp = board
    
    for y in 0..<ySz {
        for x in 0..<xSz {
            if mx<mp[y][x] {
                mx=mp[y][x]
            }
        }
    }
    
    for y in 1..<ySz {
        for x in 1..<xSz {
            if mp[y][x]==0 {continue}
            mp[y][x] = min(mp[y-1][x-1],min(mp[y][x-1],mp[y-1][x]))+1
            if mx<mp[y][x] {mx = mp[y][x]}
        }
    }

    return mx*mx
}
