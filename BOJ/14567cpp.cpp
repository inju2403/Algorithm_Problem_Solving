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

int n,m,a,b,res[MAX],inDegree[MAX];
vector<int> adj[MAX];

void topology() {
    FORS(i,1,n+1) res[i]=1;
    queue<int> q;
    FORS(i,1,n+1) if(inDegree[i]==0) q.push(i);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto next: adj[cur]) {
            if(--inDegree[next]==0) {
                q.push(next);
                res[next]=res[cur]+1;
            }
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
    topology();
    FORS(i,1,n+1) cout<<res[i]<<" ";
}
