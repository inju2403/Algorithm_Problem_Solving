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
#define MAX 10010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int k,n,mx;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>k>>n;
    v.resize(k);
    FOR(i,k) {
        cin>>v[i];
        mx=max(mx,v[i]);
    }
    ll l=1, r=mx;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll sum=0;
        FOR(i,k) sum+=v[i]/mid;
        sum>=n? l=mid+1 : r=mid-1;
    }
    cout<<l-1;
}
