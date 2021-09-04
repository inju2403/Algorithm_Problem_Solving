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

int n,m,u,v,w;
bool chk[MAX];
vector<pll> adj[MAX];

ll dijkstra(int src) {
    vector<ll> dist(n,LINF);
    dist[src]=0;
    priority_queue<pll> pq;
    pq.push({0,src});
    
    while(!pq.empty()) {
        ll cur = pq.top().second;
        ll cost = -pq.top().first;
        pq.pop();
        
        if(dist[cur] < cost) continue;
        
        for(auto next: adj[cur]) {
            ll there = next.second;
            ll nextDist = next.first + cost;
            if(chk[there]==1) continue;
            
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({-nextDist,there});
            }
        }
    }
    
    return dist[n-1]==LINF? -1 : dist[n-1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    FOR(i,n) cin>>chk[i];
    chk[n-1]=0;
    while(m--) {
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    cout<<dijkstra(0);
}
