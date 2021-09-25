#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,n,s) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 805
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n, m, a, b, c, d, e, x, y, z;
vector<pii> adj[MAX];

int dijkstra(int src,int sink) {
    vector<int> dist(n + 1, INF);
    dist[src] = 0;
    priority_queue<pii> pq;
    pq.push({ 0,src });

    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (cost > dist[here]) continue;

        FOR(i, adj[here].size()) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({ -nextDist,there });
            }
        }
    }
    return dist[sink];
}

int main() {
    cin >> n >> m;
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    cin >> d >> e;
    x = dijkstra(1, d), y = dijkstra(d, e), z = dijkstra(e, n);
    a = dijkstra(1, e), b = dijkstra(e, d), c = dijkstra(d, n);
    if ((x == INF || y == INF || z == INF)&&(a == INF || b == INF || c == INF)) {
        cout << -1;
        return 0;
    }
    cout << min((x + y + z), (a + b + c));
}
