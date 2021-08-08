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
#define MAX 55
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,x,cache[MAX];
vector<int> adj[MAX];

int dp(int cur) {
    int& ret = cache[cur];
    if(ret!=-1) return ret;
    
    ret = 0;
    vector<int> time;
    for(auto next: adj[cur]) {
        time.push_back(dp(next));
    }
    sort(time.begin(),time.end(),greater<int>());
    FOR(i,time.size()) ret = max(ret, time[i]+i+1);
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n;
    FOR(i,n) {
        cin>>x;
        if(x==-1) continue;
        adj[x].push_back(i);
    }
    cout<<dp(0);
}
