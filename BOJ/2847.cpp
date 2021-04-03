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

int n,res;
vector<int> v;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    v.resize(n);
    FOR(i,n) cin>>v[i];
    for(int i=v.size()-1;i>=1;--i) {
        if(v[i-1]>=v[i]) {
            res+=v[i-1]-(v[i]-1);
            v[i-1]=v[i]-1;
        }
    }
    cout<<res;
}
