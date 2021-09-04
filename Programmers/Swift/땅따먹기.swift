import Foundation

func solution(_ land:[[Int]]) -> Int{
    var mx = 0

    var mp = land;
    for y in 1..<mp.count {
        for x in 0..<mp[0].count {
            var mx = 0
            for px in 0..<mp[0].count {
                if x == px {continue;}
                mx = max(mx,mp[y-1][px])
            }
            mp[y][x] += mx
        }
    }
    var res = 0
    for x in 0..<mp[0].count {
        res = max(res, mp[mp.count-1][x])
    }
    return res
}
