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

int n,m,u,v,w,inDegree[MAX],dist[MAX],pre[MAX];
vector<pii> adj[MAX];
vector<int> res;

void topology() {
    queue<pii> q;
    q.push({0,1});
    while(!q.empty()) {
        int here = q.front().second;
        int cost = q.front().first;
        q.pop();
        
        for(auto next: adj[here]) {
            int there = next.second;
            int nextCost = next.first;
            if(dist[there] < cost + nextCost) {
                dist[there] = cost + nextCost;
                pre[there] = here;
            }
            if(--inDegree[there] == 0 && there != 1) {
                q.push({dist[there], there});
            }
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    while(m--) {
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        ++inDegree[v];
    }
    topology();
    cout<<dist[1]<<'\n';
    res.push_back(1);
    int before = pre[1];
    while(before!=1) {
        res.push_back(before);
        before = pre[before];
    }
    res.push_back(1);
    reverse(res.begin(), res.end());
    for(auto x: res) cout<<x<<" ";
}
