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
#define LINF 2123456789123456789
#define MAX 21
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,res=INF;
vector<string> mp,ori;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    mp.resize(n); ori.resize(n);
    FOR(i,n) cin>>mp[i];
    FOR(i,n) ori[i]=mp[i];
    FOR(i,1<<n) {
        FOR(y,n) {
            if((i&(1<<y)) == (1<<y)) {
                FOR(x,n) mp[y][x]=='T'? mp[y][x]='H' : mp[y][x]='T';
            }
        }
        FOR(x,n) {
            int cnt = 0;
            FOR(y,n) if(mp[y][x]=='T') ++cnt;
            if(cnt>n-cnt) FOR(y,n) mp[y][x]=='T'? mp[y][x]='H' : mp[y][x]='T';
        }
        
        int cur = 0;
        FOR(y,n) FOR(x,n) if(mp[y][x]=='T') ++cur;
        res = min(res,cur);
        FOR(i,n) mp[i]=ori[i];
    }
    cout<<res;
}
