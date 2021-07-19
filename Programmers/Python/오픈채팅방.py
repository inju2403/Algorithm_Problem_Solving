def solution(record):
    res = []
    id = []
    mp = {}
    exp = []
    
    for i in range(0,len(record)):
        a = record[i].split(" ");
        if a[0]=="Enter":
            mp[a[1]]=a[2]
            id.append(a[1])
            exp.append("님이 들어왔습니다.")
        elif a[0]=="Leave":
            id.append(a[1])
            exp.append("님이 나갔습니다.")
        else:
            mp[a[1]]=a[2]
            
    for i in range(0,len(exp)):
        res.append(mp[id[i]]+exp[i])
    
    return res
