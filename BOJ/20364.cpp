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
#define MAX 30
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,q,x,val;
vector<bool> visited;

void go(int cur) {
    while(cur) {
        if(visited[cur]) val = cur;
        cur/=2;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>q;
    visited.resize(n+1,0);
    while(q--) {
        val = 0;
        cin>>x;
        go(x);
        if(val==0) {
            visited[x]=1;
            cout<<0<<'\n';
        }
        else cout<<val<<'\n';
    }
}
