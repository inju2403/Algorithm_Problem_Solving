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

int n,m,k,x,idx;
bool chk[4000001];
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>k;
    v.resize(m);
    FOR(i,m) cin>>v[i];
    sort(v.begin(),v.end());
    while(k--) {
        cin>>x;
        idx = upper_bound(v.begin(), v.end(), x) - v.begin();
        while(chk[idx]) ++idx;
        chk[idx]=1;
        cout<<v[idx]<<'\n';
    }
}
