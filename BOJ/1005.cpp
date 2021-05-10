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
#define MAX 1010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int tc,n,k,a,b,w;
ll d[MAX];
vector<ll> t;
vector<int> adj[MAX];

ll dp(int cur) {
    if(adj[cur].size()==0) return d[cur] = t[cur];
    ll& ret = d[cur];
    if(ret!=-1) return ret;
    
    ret = t[cur];
    ll mx=0;
    
    for(auto child: adj[cur]) mx = max(mx, dp(child));
    return ret+=mx;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        t.clear();
        FOR(i,MAX) adj[i].clear();
        memset(d,-1,sizeof(d));
        
        cin>>n>>k;
        t.resize(n);
        FOR(i,n) cin>>t[i];
        while(k--) {
            cin>>a>>b;
            adj[b-1].push_back(a-1);
        }
        cin>>w;
        cout<<dp(w-1)<<'\n';
    }
}
