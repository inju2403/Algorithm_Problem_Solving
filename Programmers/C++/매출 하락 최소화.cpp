#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 300005

using namespace std;
typedef long long ll;

ll cache[MAX][2];
vector<int> cost,adj[MAX];

ll dp(int cur,int pre,int state) {
    ll& ret = cache[cur][state];
    if(ret!=-1) return ret;
    
    ret = 0;
    if(state == 1) {
        for(auto next: adj[cur]) {
            if(next==pre) continue;
            ret += min(dp(next,cur,0), dp(next,cur,1));
        }
    } else {
        ll add = INF;
        bool chk = 1;
        for(auto next: adj[cur]) {
            if(next==pre) continue;
            if(dp(next,cur,0) > dp(next,cur,1)) {
                chk = 0;
                ret += dp(next,cur,1);
            } else ret += dp(next,cur,0);
            add = min(add, dp(next,cur,1)-dp(next,cur,0));
        }
        if(add!=INF && chk) ret += add; // 현재노드 포함 x & 자식 모두가 포함되지 않을 경우 제일 작은애 더해줌
    }
    if(state==1) ret += cost[cur];
    return ret;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    memset(cache,-1,sizeof(cache));
    cost = sales;
    for(auto x: links) {
        adj[x[0]-1].push_back(x[1]-1);
    }
    return min(dp(0,0,0),dp(0,0,1));
}
