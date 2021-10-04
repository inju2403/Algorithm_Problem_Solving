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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,m,a,b,c,res;
vector<pii> adj[MAX];

void dfs(int cur, int pre, int dest, int cost) {
    if(cur==dest) {
        res = cost;
        return;
    }
    for(auto next: adj[cur]) {
        if(next.second == pre) continue;
        dfs(next.second, cur, dest, cost+next.first);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    FOR(i,n-1) {
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    while(m--) {
        cin>>a>>b;
        dfs(a,a,b,0);
        cout<<res<<'\n';
    }
}
