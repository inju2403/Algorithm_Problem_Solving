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
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n;
ll res;
vector<int> v;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    v.resize(n+1);
    FORS(i,1,n+1) cin>>v[i];
    sort(v.begin()+1,v.end());
    FORS(i,1,n+1) res+=abs(v[i]-i);
    cout<<res;
}
