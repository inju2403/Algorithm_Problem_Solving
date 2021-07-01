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
#define V_MAX 50005
#define EDGE_MAX 200005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int tc,n,m,x,i;
vector<int> idx,tree;

int init(int node,int nodeL,int nodeR) {
    if(nodeL==nodeR) {
        if(nodeL>=m) tree[node]=1;
        return tree[node];
    }
    int mid = (nodeL + nodeR) / 2;
    return tree[node] = init(2*node,nodeL,mid) + init(2*node+1,mid+1,nodeR);
}

int sum(int node,int nodeL,int nodeR,int l,int r) {
    if(r<nodeL || nodeR<l) return 0;
    else if(l<=nodeL && nodeR<=r) return tree[node];
    int mid=(nodeL+nodeR)/2;
    return sum(2*node,nodeL,mid,l,r) + sum(2*node+1,mid+1,nodeR,l,r);
}

int update(int node,int nodeL, int nodeR,int index,int newVal) {
    if(nodeR<index || index<nodeL) return tree[node];
    if(nodeL==nodeR) return tree[node]=newVal;
    int mid=(nodeL+nodeR)/2;
    return tree[node] = update(2*node,nodeL,mid,index,newVal)+update(2*node+1,mid+1,nodeR,index,newVal);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        cin>>n>>m;
        idx.clear(); tree.clear(); i=m-1;
        idx.resize(n); tree.resize(4*(n+m),0);
        FORS(j,m,n+m) idx[j-m]=j;
        init(1,0,n+m-1);
        FOR(iter,m) {
            cin>>x;
            --x;
            cout<<sum(1,0,n+m-1,0,idx[x]-1)<<" ";
            update(1,0,n+m-1,idx[x],0);
            idx[x]=i--;
            update(1,0,n+m-1,idx[x],1);
        }
        cout<<'\n';
    }
}
