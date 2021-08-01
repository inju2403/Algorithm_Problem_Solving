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
#define LINF 2123456789123456789
#define MAX 1005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,m,st,a,b;
bool visited[MAX];
vector<int> adj[MAX];

void dfs(int src) {
    cout<<src<<" ";
    visited[src]=1;
    for(auto next: adj[src]) {
        if(visited[next]) continue;
        dfs(next);
    }
}

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src]=1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout<<cur<<" ";
        for(auto next: adj[cur]) {
            if(visited[next]) continue;
            visited[next]=1;
            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>st;
    while(m--) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    FORS(i,1,n+1) sort(adj[i].begin(),adj[i].end());
    dfs(st);
    memset(visited,0,sizeof(visited));
    cout<<'\n';
    bfs(st);
}
