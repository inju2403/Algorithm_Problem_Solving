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

struct node {
    int idx,val;
    
    bool operator < (const node& arg) const {
        return val<arg.val;
    }
};

int n,cnt;
vector<node> v;
vector<int> res;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    v.resize(n); res.resize(n);
    FOR(i,n) {
        cin>>v[i].val;
        v[i].idx=i;
    }
    sort(v.begin(),v.end());
    res[0]=0;
    FORS(i,1,n) v[i].val==v[i-1].val? res[v[i].idx]=cnt : res[v[i].idx]=++cnt;
    FOR(i,n) cout<<res[i]<<" ";
}
