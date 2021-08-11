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

struct node {
    int u,v,w;
    bool operator < (const node& arg) const {
        return w>arg.w;
    }
};

vector<node> t;

int n,m,src,sink,a,b,c,parent[MAX];

int getParent(int x) {
    return x==parent[x]? x : parent[x]=getParent(parent[x]);
}

void merge(int a,int b) {
    a=getParent(a); b=getParent(b);
    a<b? parent[b]=a : parent[a]=b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    cin>>src>>sink;
    t.resize(n);
    FOR(i,n) parent[i]=i;
    while(m--) {
        cin>>a>>b>>c;
        t.push_back({a,b,c});
    }
    sort(t.begin(),t.end());
    for(auto x: t) {
        if(getParent(x.u)!=getParent(x.v)) {
            merge(x.u,x.v);
            if(getParent(src)==getParent(sink)) {
                cout<<x.w;
                return 0;
            }
        }
    }
}
