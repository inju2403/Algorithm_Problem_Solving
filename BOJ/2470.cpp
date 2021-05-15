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

int n,l,r,sum=2*1e9+10;
vector<int> v;
pii res;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    v.resize(n);
    FOR(i,n) cin>>v[i];
    sort(v.begin(),v.end());
    l=0, r=n-1;
    while(l<r) {
        int cur = v[r]+v[l];
        if(sum>abs(cur)) {
            sum=abs(cur);
            res={v[l],v[r]};
        }
        
        if(cur<0) ++l;
        else if(cur>0) --r;
        else {
            cout<<v[l]<<" "<<v[r];
            return 0;
        }
    }
    cout<<res.first<<" "<<res.second;
}
