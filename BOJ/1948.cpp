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
#define MAX 10010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,m,u,v,w,src,sink,mxCost[MAX],inDegree[MAX];
bool visited[MAX];
vector<pii> adj[MAX],revAdj[MAX];

int topology() {
    queue<pii> q;
    q.push({0,src});
    
    while(!q.empty()) {
        int cur = q.front().second;
        int curCost = q.front().first;
        q.pop();
        
        for(auto next: adj[cur]) {
            int there = next.second;
            int thereCost = next.first;
            
            mxCost[there] = max(mxCost[there], curCost + thereCost);
            if(--inDegree[there] == 0) q.push({mxCost[there], there});
        }
    }
    return mxCost[sink];
}

int backTrack() {
    int ret=0;
    queue<int> q;
    q.push(sink);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(auto next: revAdj[cur]) {
            int there = next.second;
            int thereCost = next.first;
            if(mxCost[there]+thereCost == mxCost[cur]) {
                ++ret;
                if(visited[there]) continue;
                visited[there]=1;
                q.push(there);
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    while(m--) {
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        revAdj[v].push_back({w,u});
        
        inDegree[v]++;
    }
    cin>>src>>sink;
    cout<<topology()<<'\n';
    cout<<backTrack();
}
