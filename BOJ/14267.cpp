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
#define MAX 100010
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,m,a,b,d[MAX];
vector<int> adj[MAX];

void dfs(int idx) {
    for(auto next: adj[idx]) {
        d[next] += d[idx];
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    FORS(i,1,n+1) {
        cin>>a;
        if(a==-1) continue;
        adj[a].push_back(i);
    }
    while(m--) {
        cin>>a>>b;
        d[a] += b;
    }
    dfs(1);
    FORS(i,1,n+1) cout<<d[i]<<" ";
}
