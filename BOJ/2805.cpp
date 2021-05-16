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
#define MAX 10010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,m;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    v.resize(n);
    FOR(i,n) cin>>v[i];
    int l=1, r=1e9+1;
    while(l<=r) {
        int mid = (l+r)/2;
        ll sum = 0;
        FOR(i,n) if(v[i]>mid) sum+=v[i]-mid;
        sum>=m? l=mid+1 : r=mid-1;
    }
    cout<<l-1;
}
