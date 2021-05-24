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
#define MAX 65
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int tc,n;
ll d[MAX][10],res[MAX]; // d[a][b]: a자릿수에서 맨 뒷자리가 b인 줄어들지 않는 자릿수의 개수

int main() {
    FOR(i,10) d[1][i]=1;
    res[1]=10;
    FORS(i,2,MAX) {
        FOR(j,10) {
            FOR(k,j+1) d[i][j]+=d[i-1][k];
            res[i]+=d[i][j];
        }
    }
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        cin>>n;
        cout<<res[n]<<'\n';
    }
}
