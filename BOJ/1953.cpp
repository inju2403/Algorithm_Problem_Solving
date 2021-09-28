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
#define LINF 9123456789123456789
#define MAX 105
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,k,a;
bool visited[MAX];
vector<int> adj[MAX],v1,v2;

void dfs(int x,int a) {
    a==0? v1.push_back(x) : v2.push_back(x);
    for(auto next: adj[x]) {
        if(visited[next]) continue;
        visited[next]=1;
        a==0? dfs(next,1) : dfs(next,0);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    FORS(i,1,n+1) {
        cin>>k;
        while(k--) {
            cin>>a;
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
    }
    FORS(i,1,n+1) {
        if(!visited[i]) {
            visited[i]=1;
            dfs(i,0);
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    cout<<v1.size()<<'\n';
    for(auto next: v1) cout<<next<<" ";
    cout<<'\n'<<v2.size()<<'\n';
    for(auto next: v2) cout<<next<<" ";
}
