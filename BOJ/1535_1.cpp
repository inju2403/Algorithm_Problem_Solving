#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,w[21],v[21],cache[21][101];

int dp(int n,int k) {
    if(k<=0) return -987654321;
    if(n==-1) return 0;
    int &ret = cache[n][k];
    if(ret!=-1) return ret;
    return ret=max(dp(n-1, k-w[n])+v[n], dp(n-1,k));
}

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n;
    FOR(i,n) cin>>w[i];
    FOR(i,n) cin>>v[i];
    cout<<dp(n,100);
}
