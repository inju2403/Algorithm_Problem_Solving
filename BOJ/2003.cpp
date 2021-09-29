#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
#include<numeric>
#include<tuple>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 105
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<vector<int> > vii;

int n,m,cnt,sum,l,r;
vector<int> v;

int main() {
    cin>>n>>m;
    v.resize(n);
    FOR(i,n) scanf("%d",&v[i]);
    while(!(r==n&&sum<m)) {
        if(sum==m) ++cnt;
        if(sum>=m) sum-=v[l++];
        else sum+=v[r++];
    }
    cout<<cnt;
}
