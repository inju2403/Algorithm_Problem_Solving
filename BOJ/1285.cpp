#include<iostream>
#include<vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,m;
vector<int> v;

void dfs(int x,vector<int> &v) {
    if(v.size()==m) {
        FOR(i,m) cout<<v[i]<<" ";
        cout<<'\n';
        return;
    }
    FORS(next,x,n+1) {
        v.push_back(next);
        dfs(next+1,v);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    dfs(1,v);
}
