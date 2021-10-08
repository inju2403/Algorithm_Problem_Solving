#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
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
#define MAX 1010
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int tc,n,m,u,v,w,cache[MAX];
vector<pii> adj[MAX];

int dp(int cur, int pre) {
    int& ret = cache[cur];
    if(ret!=-1) return ret;
    
    ret = 0;
    for(auto next: adj[cur]) {
        int there = next.second;
        int dist = next.first;
        if(there==pre) continue;
        ret += min(dist, dp(there, cur));
    }
    if(ret==0) ret = INF;
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        memset(cache,-1,sizeof(cache));
        FOR(i,MAX) adj[i].clear();
        cin>>n>>m;
        while(m--) {
            cin>>u>>v>>w;
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }
        cout<<(dp(1,1)==INF? 0 : dp(1,1))<<'\n';
    }
}
