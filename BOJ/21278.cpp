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
#define MAX 110
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,m,a,b,mn=INF,dist[MAX][MAX];

void floyd() {
    FORS(k,1,n+1) FORS(i,1,n+1) FORS(j,1,n+1) {
        dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    FORS(i,1,n+1) FORS(j,1,n+1) if(i!=j) dist[i][j]=INF;
    while(m--) {
        cin>>a>>b;
        dist[a][b]=1;
        dist[b][a]=1;
    }
    floyd();
    FORS(i,1,n+1) FORS(j,i+1,n+1) {
        int sum = 0;
        FORS(k,1,n+1) sum += min(dist[i][k], dist[j][k]);
        if(mn > sum) {
            mn = sum;
            a=i, b=j;
        }
    }
    cout<<a<<" "<<b<<" "<<2*mn;
}
