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

int n,l,r,res[3];
ll sum=3e9+10;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    v.resize(n);
    FOR(i,n) cin>>v[i];
    sort(v.begin(),v.end());
    FOR(i,n-2) {
        l=i+1, r=n-1;
        while(l<r) {
            ll cur = (ll)v[i]+v[l]+v[r];
            if(sum>abs(cur)) {
                sum=abs(cur);
                res[0]=v[i];
                res[1]=v[l];
                res[2]=v[r];
                
                if(sum==0) {
                    FOR(i,3) cout<<res[i]<<" ";
                    return 0;
                }
            }
            
            if(cur<0) ++l;
            else if(cur>0) --r;
        }
    }
    FOR(i,3) cout<<res[i]<<" ";
}
