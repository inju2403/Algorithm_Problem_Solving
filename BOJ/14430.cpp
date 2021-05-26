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
#define MAX 301
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,m,mp[MAX][MAX],cache[MAX][MAX];

int dp(int y,int x) {
    if(y<0 || x<0) return 0;
    
    int& ret = cache[y][x];
    if(ret!=-1) return ret;

    ret = mp[y][x];
    return ret += max(dp(y-1,x), dp(y,x-1));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n>>m;
    FOR(i,n) FOR(j,m) cin>>mp[i][j];
    cout<<dp(n-1,m-1);
}
