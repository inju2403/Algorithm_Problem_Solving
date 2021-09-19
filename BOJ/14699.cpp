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
#define MAX 5010
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,m,a,b,h[MAX],cache[MAX];
vector<int> adj[MAX];

int dp(int cur) {
    int& ret = cache[cur];
    if(ret!=-1) return ret;
    
    ret = 0;
    for(auto next: adj[cur]) {
        if(h[next] > h[cur]) {
            ret = max(ret, dp(next));
        }
    }
    ret += 1;
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n>>m;
    FORS(i,1,n+1) cin>>h[i];
    while(m--) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    FORS(i,1,n+1) cout<<dp(i)<<'\n';
}
