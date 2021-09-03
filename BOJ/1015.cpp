#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
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
#define MAX 105
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

struct node {
    int val,idx;
    bool operator < (const node& arg) const {
        if(val != arg.val ) return val<arg.val;
        return idx<arg.idx;
    }
};

int n,x;
vector<node> v;
vector<int> res;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    FOR(i,n) {
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    res.resize(n);
    FOR(i,n) res[v[i].idx]=i;
    FOR(i,n) cout<<res[i]<<" ";
}
