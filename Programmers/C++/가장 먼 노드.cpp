#include <string>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 20010

using namespace std;
typedef pair<int,int> pii;

int n;
vector<int> adj[MAX];

int dijkstra(int src) {
    vector<int> dist(n+1,INF);
    dist[src] = 0;
    priority_queue<pii> pq;
    pq.push({0,src});
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        if(dist[cur] < cost) continue;
        
        for(auto next: adj[cur]) {
            if(dist[next] > cost+1) {
                dist[next] = cost+1;
                pq.push({-(cost+1),next});
            }
        }
    }
    
    int mx = 0, cnt = 0;
    FORS(i,2,n+1) mx = max(mx,dist[i]);
    FORS(i,2,n+1) if(dist[i]==mx) ++cnt;
    return cnt;
}

int solution(int N, vector<vector<int>> edge) {
    n = N;
    for(auto x: edge) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    return dijkstra(1);
}
