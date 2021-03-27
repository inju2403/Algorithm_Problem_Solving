#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,w[22],v[22],res;

void dfs(int x,int k, int sum) {
    if(k<=0) return;
    if(x==n+1) {
        res=max(res,sum);
        return;
    }
    dfs(x+1,k-w[x],sum+v[x]);
    dfs(x+1,k,sum);
}

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    FORS(i,1,n+1) cin>>w[i];
    FORS(i,1,n+1) cin>>v[i];
    dfs(1,100,0);
    cout<<res;
}
