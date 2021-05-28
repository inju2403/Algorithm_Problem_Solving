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
#define MAX 1000001
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,cache[MAX];

int dp(int x) {
    if(x==1) return 0;
    
    int& ret = cache[x];
    if(ret!=-1) return ret;
    
    ret=INF;
    if(x%3==0) ret = min(ret, dp(x/3)+1);
    if(x%2==0) ret = min(ret, dp(x/2)+1);
    if(x%6!=0) ret = min(ret, dp(x-1)+1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n;
    cout<<dp(n);
}
