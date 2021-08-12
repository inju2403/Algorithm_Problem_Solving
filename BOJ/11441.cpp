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

int n,m,a,b;
vector<int> sum;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    sum.resize(n);
    FOR(i,n) cin>>sum[i];
    FORS(i,1,n) sum[i]+=sum[i-1];
    cin>>m;
    while(m--) {
        cin>>a>>b;
        cout<<(a==1? sum[b-1] : sum[b-1]-sum[a-2])<<'\n';
    }
}
