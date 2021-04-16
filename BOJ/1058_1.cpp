#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 51
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,res;
string s;
vector<int> adj[MAX];
bool visited[MAX];

void go(int x) {
    visited[x]=1;
    for(auto next: adj[x]) visited[next]=1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    FOR(i,n) {
        cin>>s;
        FOR(j,s.size()) if(s[j]=='Y') adj[i].push_back(j);
    }
    FOR(i,n) {
        memset(visited,0,sizeof(visited));
        for(auto next: adj[i]) go(next);
        int sum=0;
        FOR(j,n) sum+=visited[j];
        res=max(res,sum-1);
    }
    cout<<res;
}
