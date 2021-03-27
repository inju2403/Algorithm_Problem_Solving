#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;
typedef pair<int,int> pii;

int N,M,d[101][10001];
vector<int> m,c;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>N>>M;
    m.resize(N+1); c.resize(N+1);
    FORS(i,1,N+1) cin>>m[i];
    FORS(i,1,N+1) cin>>c[i];
    //d[i][x]: 1~i번째 앱들을 끄거나 켜고 x 손실을 봤을 때 확보할 수 있는 최대 메모리
    FORS(i,1,N+1) {
        FOR(j,10001) {
            if(j>=c[i]) d[i][j] = max(d[i-1][j-c[i]]+m[i], d[i-1][j]);
            else d[i][j] = d[i-1][j];
        }
    }
    FOR(j,10001) if(d[N][j]>=M) {
        cout<<j;
        break;
    }
}
