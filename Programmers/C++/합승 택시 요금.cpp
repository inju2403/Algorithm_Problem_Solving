#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define LINF 9123456789123456789
#define MAX 205

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

ll mn=LINF, dist[3][MAX];
vector<pii> adj[MAX];

void dijkstra(int src,int idx) {
    FOR(i,MAX) dist[idx][i]=LINF;
    dist[idx][src]=0;
    priority_queue<pii> pq; // 비용, 지점
    pq.push({0,src});
    
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[idx][here] < cost) continue;
        
        for(auto next: adj[here]) {
            int nextCost = cost + next.first;
            int there = next.second;
            if(dist[idx][there] > nextCost) {
                dist[idx][there] = nextCost;
                pq.push({-nextCost,there});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(auto x: fares) {
        adj[x[0]].push_back({x[2],x[1]});
        adj[x[1]].push_back({x[2],x[0]});
    }
    dijkstra(s,0);
    dijkstra(a,1);
    dijkstra(b,2);
    
    FORS(i,1,n+1) mn = min(mn, dist[0][i]+dist[1][i]+dist[2][i]);
    
    return mn;
}
