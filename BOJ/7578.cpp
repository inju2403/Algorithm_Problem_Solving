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
#define MAX 1000005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int x,n,idx[MAX];
ll res;
vector<ll> order,tree;

ll sum(int node, int nodeL, int nodeR, int l, int r) {
    if(r<nodeL || nodeR<l) return 0;
    if(l<=nodeL && nodeR<=r) return tree[node];
    int mid = (nodeL+nodeR)/2;
    return sum(2*node, nodeL, mid, l, r) + sum(2*node+1, mid+1, nodeR, l, r);
}

ll update(int node, int nodeL, int nodeR, int idx, int newVal) {
    if(idx<nodeL || nodeR<idx) return tree[node];
    if(nodeL==nodeR) return tree[node] = newVal;
    int mid = (nodeL+nodeR)/2;
    return tree[node] = update(2*node, nodeL, mid, idx, newVal) + update(2*node+1, mid+1, nodeR, idx, newVal);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    tree.resize(4*n);
    FOR(i,n) {
        cin>>x;
        order.push_back(x);
    }
    FOR(i,n) {
        cin>>x;
        idx[x]=i;
    }
    FOR(i,order.size()) {
        res += sum(1, 0, n-1, idx[order[i]] + 1, n-1);
        update(1, 0, n-1, idx[order[i]], 1);
    }
    cout<<res;
}
