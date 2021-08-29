import Foundation

var res = 0
var str = [Character]()
var st = [Character]()

func judge(_ s:[Character]) {
    var chk = true
    for c in s {
        if c=="{" || c=="[" || c=="(" {st.append(c)}
        else {
            if st.count==0
            || c=="}" && st[st.count-1] != "{"
            || c==")" && st[st.count-1] != "("
            || c=="]" && st[st.count-1] != "[" {
                chk = false
                break
            }
            st.removeLast()
        }
    }
    if st.count>0 {chk=false}
    if chk == true {res+=1}
}

func solution(_ s:String) -> Int {
    
    str = Array(s)
    for i in 0..<s.count {
        var arg = [Character]()
        for j in i..<s.count {
            arg.append(str[j])
        }
        for j in 0..<i {
            arg.append(str[j])
        }
        judge(arg)
    }
    return res
}
