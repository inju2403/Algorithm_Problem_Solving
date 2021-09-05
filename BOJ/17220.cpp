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
#define MAX 30
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,m,res;
char a,b;
bool visited[MAX];
vector<int> adj[MAX];
set<char> st;
unordered_map<char, bool> inDegree,chk;

void dfs(char parent) {
    for(auto next: adj[parent-'A']) {
        if(visited[next]) continue;
        if(chk.count(next+'A')) continue;
        visited[next]=1;
        ++res;
        dfs(next+'A');
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    while(m--) {
        cin>>a>>b;
        adj[a-'A'].push_back(b-'A');
        inDegree[b]=true;
        st.insert(a);
        st.insert(b);
    }
    cin>>m;
    while(m--) {
        cin>>a;
        chk[a]=true;
    }
    for(auto x: st) {
        if(inDegree.count(x)==0 && chk.count(x)==0) {
            dfs(x);
        }
    }
    cout<<res;
}
