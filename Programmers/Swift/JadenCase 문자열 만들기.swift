func solution(_ s:String) -> String {
    
    var ary = Array(s)
    var res = [Character]()
    var chk = false
    
    for c in ary {
        if chk == false {
            res.append(Character(c.uppercased()))
            if c != " " {chk = true}
        }
        else {
            res.append(Character(c.lowercased()))
            if c == " " {
                chk = false
            }
        }
    }
    
    return res.map{String($0)}.joined()
}
