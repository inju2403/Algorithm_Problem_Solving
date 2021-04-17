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

int n;
vector<int> v;
bool visited[10];

void dfs(int cur,vector<int>& v) {
    if(v.size()==n) {
        FOR(i,n) cout<<v[i]<<" ";
        cout<<'\n';
        return;
    }
    FORS(i,1,n+1) {
        if(visited[i]) continue;
        v.push_back(i); visited[i]=1;
        dfs(i,v);
        v.pop_back(); visited[i]=0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    dfs(1,v);
}
