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

int n,m,res,sum;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    v.resize(m);
    FOR(i,m) cin>>v[i];
    sort(v.begin(),v.end());
    FOR(i,m) {
        if(sum<v[i]*(min(n,(m-1)-(i-1)))) {
            res=v[i];
            sum=v[i]*(min(n,(m-1)-(i-1)));
        }
    }
    cout<<res<<" "<<sum;
}
