def solution(N, stages):
    res = []
    v = []
    sum = [0 for _ in range(1,N+1)]
    sum.append(0)
    mp = {} # int, int
    total = len(stages)
    
    for i in range(1,N+2):
        mp[i]=0
        
    for x in stages:
        mp[x]+=1
    
    for i in range(1,N+1):
        sum[i] = sum[i-1] + mp[i]
        
    for i in range(1,N+1):
        dv = total - sum[i-1]
        f = 0
        if dv!=0:
            f = mp[i] / dv
        v.append((f,i))
            
    v.sort(key = lambda x : (-x[0], x[1]))
    
    for x in v:
        res.append(x[1])
    return res
