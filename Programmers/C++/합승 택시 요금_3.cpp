#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define LINF 9123456789123456789
#define MAX 210

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n;
ll res=LINF;
vector<ll> d1,d2,d3;
vector<pii> adj[MAX];

void djikstra(int src, vector<ll>& dist) {
    dist.resize(n+1,LINF);
    dist[src]=0;
    priority_queue<pii> pq;
    pq.push({0,src});
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[cur] < cost) continue;
        
        for(auto next: adj[cur]) {
            int there = next.second;
            int nextCost = cost + next.first;
            if(dist[there] > nextCost) {
                dist[there] = nextCost;
                pq.push({-nextCost,there});
            }
        }
    }
}

using namespace std;

int solution(int N, int s, int a, int b, vector<vector<int>> fares) {
    n=N;
    for(auto x: fares) {
        adj[x[0]].push_back({x[2],x[1]});
        adj[x[1]].push_back({x[2],x[0]});
    }
    
    djikstra(s,d1);
    djikstra(a,d2);
    djikstra(b,d3);
    
    FORS(i,1,n+1) {
        res=min(res,d1[i]+d2[i]+d3[i]);
    }
    
    return res;
}
