#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,cnt=1,res=1;
char mp[51][51];

void go() {
    FOR(Y,n) {
        cnt=1;
        FOR(X,n-1) {
            if(mp[Y][X]==mp[Y][X+1]) {
                ++cnt;
                res=max(res,cnt);
            }
            else cnt=1;
        }
    }
    FOR(X,n) {
        cnt=1;
        FOR(Y,n-1) {
            if(mp[Y][X]==mp[Y+1][X]) {
                ++cnt;
                res=max(res,cnt);
            }
            else cnt=1;
        }
    }
}

void func(int y,int x) {
    if(x+1<n && mp[y][x]!=mp[y][x+1]) {
        swap(mp[y][x], mp[y][x+1]);
        go();
        swap(mp[y][x], mp[y][x+1]);
    }
    if(y+1<n && mp[y][x]!=mp[y+1][x]) {
        swap(mp[y][x], mp[y+1][x]);
        go();
        swap(mp[y][x], mp[y+1][x]);
    }
}

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    FOR(y,n) FOR(x,n) cin>>mp[y][x];
    FOR(y,n) FOR(x,n) func(y,x);
    cout<<res;
}
