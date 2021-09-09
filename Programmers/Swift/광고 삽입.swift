import Foundation

func solution(_ play_time:String, _ adv_time:String, _ logs:[String]) -> String {

    let playTime = play_time.split(separator:":").map{Int($0)!}.reduce(0){ $0*60 + $1 } //$0:누적 값, $1:새로운 값
    let advTime = adv_time.split(separator:":").map{Int($0)!}.reduce(0){ $0*60 + $1 }
    var t = [Int](repeating:0, count: playTime+1)
    
    for k in logs {
        let v = k.split(separator:"-")
        let st = v[0].split(separator:":").map{Int($0)!}.reduce(0) { $0*60 + $1}
        let ed = v[1].split(separator:":").map{Int($0)!}.reduce(0) { $0*60 + $1}
        
        t[st] += 1
        t[ed] -= 1
    }
    
    for i in 1..<playTime {
        t[i] += t[i-1]
    }
    
    var sum = 0
    for i in 0..<advTime { sum += t[i] }
    var mx = sum
    var idx = 0
    
    var l = 0
    var r = advTime-1
    
    while r < playTime - 1 {
        sum -= t[l]
        l += 1
        r += 1
        sum += t[r]
        if mx < sum {
            mx = sum
            idx = l
        }
    }
    
    return String(format: "%02d:%02d:%02d", idx / (60*60), (idx / 60) % 60, idx % 60)
}
