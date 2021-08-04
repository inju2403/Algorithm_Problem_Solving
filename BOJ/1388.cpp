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
#define MAX 105
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,m,res,mp[MAX][MAX];
char c;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    FOR(y,n) FOR(x,m) {
        cin>>c;
        mp[y][x] = c=='-'? 0 : 1;
    }
    FOR(y,n) {
        bool chk = 0;
        FOR(x,m) {
            int k = mp[y][x];
            // '-'
            if(k==0) chk=1;
            else {
                if(chk) {
                    chk=0;
                    ++res;
                }
            }
        }
        if(chk) ++res;
    }
    
    FOR(x,m) {
        bool chk = 0;
        FOR(y,n) {
            int k = mp[y][x];
            // '|'
            if(k==1) chk=1;
            else {
                if(chk) {
                    chk=0;
                    ++res;
                }
            }
        }
        if(chk) ++res;
    }
    cout<<res;
}
