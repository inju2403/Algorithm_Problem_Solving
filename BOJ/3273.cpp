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
#define MAX 110
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,k,res;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    v.resize(n);
    FOR(i,n) cin>>v[i];
    cin>>k;
    sort(v.begin(),v.end());
    int l = 0, r = n-1;
    while(l<r) {
        if(v[l]+v[r]==k) ++res;
        if(v[l]+v[r] >= k) --r;
        else ++l;
    }
    cout<<res;
}
