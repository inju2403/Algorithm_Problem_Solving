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
#define MAX 1005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int tc,l,n,mx,mn;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        mx=0; mn=0;
        cin>>l>>n;
        v.clear(); v.resize(n);
        FOR(i,n) cin>>v[i];
        FOR(i,n) mx = max({mx,v[i],l-v[i]});
        FOR(i,n) {
            int cur = min(v[i],l-v[i]);
            mn = max(mn, cur);
        }
        cout<<mn<<" "<<mx<<"\n";
    }
}
