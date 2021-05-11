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

int n,m,l,inDegree[MAX];
bool chk;
vector<int> res,v,adj[MAX];

void topologySort() {
    queue<int> q;
    FORS(i,1,n+1) if(!inDegree[i]) q.push(i);
    
    FORS(i,1,n+1) {
        if(q.empty()) {
            chk=1;
            break;
        }
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        
        for(auto next: adj[cur]) {
            if(--inDegree[next]==0) q.push(next);
        }
    }
    if(chk) cout<<0;
    else FOR(i,res.size()) cout<<res[i]<<'\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    while(m--) {
        cin>>l;
        v.clear(); v.resize(l);
        FOR(i,l) cin>>v[i];
        FOR(i,l-1) {
            adj[v[i]].push_back(v[i+1]);
            inDegree[v[i+1]]++;
        }
        
    }
    topologySort();
}
