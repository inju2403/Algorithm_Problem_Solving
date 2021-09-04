import Foundation


func solution(_ new_id:String) -> String {
    
    //1
    var id = new_id.map{Character(Character(String($0)).lowercased())}
    
    //2
    id = id.filter{$0.isLetter || $0.isNumber || $0=="-" || $0=="_" || $0=="."}
    
    //3
    var res = [Character]()
    res.append(id[0])
    for i in 1..<id.count {
        if id[i]=="." && id[i-1]=="." {continue}
        res.append(id[i])
    }
    
    //4
    if res.count>0 && res[0]=="." {res.removeFirst()}
    if res.count>0 && res[res.count-1]=="." {res.removeLast()}
    
    //5
    if res.count == 0 {res.append("a")}

    //6
    if res.count >= 16 {
         var tmp = res
        res = [Character]()
        for i in 0..<15 {res.append(tmp[i])}
    }
    if res[res.count-1]=="." {res.removeLast()}
    
    //7
    let c = res[res.count-1]
    while res.count<=2 {res.append(c)}
    
    return res.map{String($0)}.joined()
}
