let n = readLine()!
let p = readLine()!
    .split(separator: " ")
    .map{ Int($0)! }
let res = p.reduce(0, ^)
print(res==0 ? "cubelover" : "koosaga")
