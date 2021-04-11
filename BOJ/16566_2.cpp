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

int n,m,k,x,idx,parent[4000001];
vector<int> v;

int getParent(int x) {
    return x==parent[x]? x : parent[x] = getParent(parent[x]);
}

void merge(int a,int b) {
    a=getParent(a), b=getParent(b);
    a>b? parent[b]=a : parent[a]=b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>k;
    FORS(i,1,n+1) parent[i]=i;
    v.resize(m);
    FOR(i,m) cin>>v[i];
    sort(v.begin(),v.end());
    while(k--) {
        cin>>x;
        idx = getParent(upper_bound(v.begin(), v.end(), x) - v.begin());
        merge(idx,idx+1);
        cout<<v[idx]<<'\n';
    }
}
