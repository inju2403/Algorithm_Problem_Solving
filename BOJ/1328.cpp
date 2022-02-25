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
#define MAX 101
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,l,r;
ll dp[MAX][MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>l>>r;
    dp[1][1][1] = 1;
    FORS(i,2,n+1) FORS(j,1,l+1) FORS(k,1,r+1) {
        dp[i][j][k] = (dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k] * (i-2)) % MOD;
    }
    cout<<dp[n][l][r];
}
