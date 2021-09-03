import Foundation

func solution(_ s:String) -> Bool
{
    var n = 0
    for i in s {
        if i=="(" {n+=1}
        else {
            n-=1
            if n<0 {return false}
        }
    }
    if n==0 {return true}
    else {return false}
}
