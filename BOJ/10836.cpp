#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 300001
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,k,a,b,c;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    v.resize(2*n-1,1);
    FOR(i,k) {
        cin>>a>>b>>c;
        FORS(i,a,a+b) ++v[i];
        FORS(i,a+b,a+b+c) v[i]+=2;
    }
    FOR(y,n) {
        FOR(x,n) cout<<(x==0? v[(n-1)-y] : v[(n-1)+x])<<" ";
        cout<<'\n';
    }
}
