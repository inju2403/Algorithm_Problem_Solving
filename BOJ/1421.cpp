#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,c,w,mx,wood,cut;
ll res,sum;
vector<int> v;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n>>c>>w;
    v.resize(n);
    FOR(i,n) {
        cin>>v[i];
        mx=max(mx,v[i]);
    }
    FORS(i,1,mx+1) {
        sum=0;
        FOR(j,n) {
            if(v[j]<i) continue;
            wood=v[j]/i;
            cut=(v[j]-1)/i;
            if(wood*w*i > cut*c) sum += wood*w*i - cut*c;
        }
        res=max(res,sum);
    }
    cout<<res;
}
