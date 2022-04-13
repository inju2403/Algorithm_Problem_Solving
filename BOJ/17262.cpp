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
#define MAX 100005
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,l,r,s=INF,e;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    FOR(i,n) {
        cin>>l>>r;
        s=min(s,r);
        e=max(e,l);
    }
    if(s>e) cout<<0;
    else cout<<e-s;
}
