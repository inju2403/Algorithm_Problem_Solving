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
#define MAX 10005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int tc,n;
bool judge;
vector<string> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        judge = 1;
        cin>>n;
        v.resize(n);
        FOR(i,n) cin>>v[i];
        sort(v.begin(), v.end());
        FOR(i,n-1) {
            if(v[i] == v[i+1].substr(0,v[i].size())) {
                cout<<"NO\n";
                judge = 0;
                break;
            }
        }
        if(judge) cout<<"YES\n";
    }
}
