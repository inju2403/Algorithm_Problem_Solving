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
#define MAX 55
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

struct node {
    int u,v,w;
    bool operator < (const node& arg) const {
        return w<arg.w;
    }
};

vector<node> t;
vector<int> v;
vector<vector<int>> vi;

int n,m,k,a,b,res,parent[MAX];

int getParent(int x) {
    if(x==-1) return -1;
    return x==parent[x]? x : parent[x]=getParent(parent[x]);
}

void merge(int a,int b) {
    a=getParent(a); b=getParent(b);
    a<b? parent[b]=a : parent[a]=b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    t.resize(n);
    FOR(i,n+1) parent[i]=i;
    cin>>k; v.resize(k);
    FOR(i,k) cin>>v[i];
    FOR(i,k) parent[v[i]]=-1;
    while(m--) {
        cin>>a;
        vector<int> cur(a,0);
        FOR(i,a) cin>>cur[i];
        FOR(i,a-1) merge(cur[i],cur[i+1]);
        vi.push_back(cur);
    }
    for(auto x: vi) {
        bool judge = 1;
        FOR(i,x.size()) {
            if(getParent(x[i])==-1) {
                judge=0;
                break;
            }
        }
       if(judge) ++res;
    }
    cout<<res;
}
