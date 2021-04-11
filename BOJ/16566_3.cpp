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
#define INF 987654321
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,m,k,x;
vector<int> v,tree;

int init(int node, int nodeL, int nodeR) {
    if(nodeL==nodeR) return tree[node]=v[nodeL];
    int mid=(nodeL+nodeR)/2;
    return tree[node] = min(init(node*2,nodeL,mid), init(node*2+1,mid+1,nodeR));
}

int query(int node,int nodeL,int nodeR,int l,int r) {
    if(nodeR<l || r<nodeL) return INF;
    else if(l<=nodeL && nodeR<=r) return tree[node];
    else {
        int mid=(nodeL+nodeR)/2;
        return min(query(node*2,nodeL,mid,l,r), query(node*2+1,mid+1,nodeR,l,r));
    }
}

int update(int node,int nodeL,int nodeR,int idx,int newVal) {
    if(idx<nodeL || nodeR<idx) return tree[node];
    else if(nodeL==nodeR) return tree[node]=newVal;
    else {
        int mid=(nodeL+nodeR)/2;
        return tree[node] = min(update(node*2,nodeL,mid,idx,newVal), update(node*2+1,mid+1,nodeR,idx,newVal));
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>k;
    v.resize(n+1); tree.resize(4*(n+1));
    FORS(i,1,n+1) v[i]=INF;
    FOR(i,m) {
        cin>>x;
        v[x]=x;
    }
    init(1,1,n);
    while(k--) {
        cin>>x;
        int val=query(1,1,n,x+1,n);
        cout<<val<<'\n';
        update(1,1,n,val,INF);
    }
}
