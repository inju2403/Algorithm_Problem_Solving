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
#define MAX 510
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int tc,cs=1,n,m,a,b,res;
bool judge,visited[MAX];
vector<int> adj[MAX];

void dfs(int cur, int pre) {
    for(auto next: adj[cur]) {
        if(next==pre) continue;
        if(visited[next]) {
            judge = 0;
            break;
        }
        visited[next]=1;
        dfs(next, cur);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while(1) {
        res=0;
        memset(visited,0,sizeof(visited));
        FOR(i,MAX) adj[i].clear();
        cin>>n>>m;
        if(n==0&&m==0) break;
        while(m--) {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        FORS(i,1,n+1) {
            if(!visited[i]) {
                visited[i]=1;
                judge = 1;
                dfs(i,i);
                if(judge) ++res;
            }
        }
        cout<<"Case "<<cs<<": ";
        if(res==0) cout<<"No trees.\n";
        else if(res==1) cout<<"There is one tree.\n";
        else cout<<"A forest of "<<res<<" trees.\n";
        ++cs;
    }
}
