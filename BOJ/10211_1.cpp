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

int tc,n,x,res=-1000;
vector<int> sum;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>tc;
    while(tc--) {
        res=-1000;
        cin>>n;
        sum.resize(n);
        FOR(i,n) {
            cin>>x;
            res=max(res,x);
            sum[i]=sum[i-1]+x;
        }
        FORS(i,-1,n) {
            int s=0;
            FORS(j,i+1,n) {
                s=sum[j]-sum[i];
                res=max(res,s);
            }
        }
        cout<<res<<'\n';
    }
}
