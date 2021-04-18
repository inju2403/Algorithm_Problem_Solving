#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 10001
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,l,a,b,c;
vector<pii> adj[MAX];

int dijkstra(int src) {
    vector<int> dist(l+1,INF);
    dist[src] = 0;
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
        if(cur+1<=l && dist[cur+1]>cost+1) {
            dist[cur+1]=cost+1;
            pq.push({-(cost+1),cur+1});
        }
    }
    return dist[l];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>l;
    while(n--) {
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
    }
    cout<<dijkstra(0);
}
