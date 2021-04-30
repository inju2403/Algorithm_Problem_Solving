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
#define MAX 105
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,t;
vector<pii> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    v.resize(n);
    FOR(i,n) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    FOR(i,n) {
        if(t<v[i].first) t=v[i].first+v[i].second;
        else t+=v[i].second;
    }
    cout<<t;
}
