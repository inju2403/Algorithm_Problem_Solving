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
#define MAX 32010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,m,a,b,inDegree[MAX];
vector<int> adj[MAX];

void topologySort() {
    priority_queue<int> pq;
    FORS(i,1,n+1) if(!inDegree[i]) pq.push(-i);
    
    while(!pq.empty()) {
        int cur = -pq.top();
        cout<<cur<<" ";
        pq.pop();
        
        for(auto next: adj[cur]) {
            if(--inDegree[next]==0) pq.push(-next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    while(m--) {
        cin>>a>>b;
        adj[a].push_back(b);
        ++inDegree[b];
    }
    topologySort();
}
