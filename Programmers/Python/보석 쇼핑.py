st = set()
hash = {}

def solution(gems):
    for x in gems:
        st.add(x)
    ln = len(gems)
    sz = len(st)
    l=0
    r=0
    hash[gems[0]] = 1
    res = []
    mn = 987654321
    while r<ln:
        if len(hash) < sz:
            r += 1
            if r == ln:
                break
            if gems[r] in hash:
                num = hash[gems[r]]
                hash[gems[r]] = num + 1
            else:
                hash[gems[r]] = 1
        else:
            if mn > r-l:
                mn = r-l;
                res.clear()
                res.append(l+1)
                res.append(r+1)
            if gems[l] in hash:
                num = hash[gems[l]]
                hash[gems[l]] = num - 1
            if hash[gems[l]] == 0:
                del hash[gems[l]]
            l += 1
    
    return res
