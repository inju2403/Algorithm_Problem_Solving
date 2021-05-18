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
#define MAX 500010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,a,b,res;
vector<int> adj[MAX];

void dfs(int cur,int pre,int depth) {
    if(cur!=1 && adj[cur].size()==1) {
        res+=depth;
        return;
    }
    
    for(auto next: adj[cur]) {
        if(next==pre) continue;
        dfs(next,cur,depth+1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    while(--n) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1,0);
    cout<<(res%2? "Yes" : "No");
}
