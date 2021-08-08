#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define LINF 9123456789123456789
#define MAX 10005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,a,b,cache[MAX][2];
vector<int> cost,adj[MAX];

int dp(int cur,int pre,int state) {
    int& ret = cache[cur][state];
    if(ret!=-1) return ret;
    
    ret = 0;
    for(auto next: adj[cur]) {
        if(next==pre) continue;
        if(state==0) ret += max(dp(next,cur,0), dp(next,cur,1));
        else ret += dp(next,cur,0);
    }
    if(state==1) ret += cost[cur];
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n;
    cost.resize(n);
    FOR(i,n) cin>>cost[i];
    FOR(i,n-1) {
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    cout<<max(dp(0,0,0),dp(0,0,1));
}
