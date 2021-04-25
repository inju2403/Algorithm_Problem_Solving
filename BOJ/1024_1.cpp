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
#define MAX 501
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

ll n,len,mn=LINF,l,r,sum;
pii res;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>len;
    while(r<n+1) {
        if(sum>=n) {
            sum-=l;
            ++l;
        }
        else {
            sum+=r;
            ++r;
        }
        if(sum==n) {
            if(len <= r-l && r-l<=100) {
                if(mn > r-l) {
                    mn = r-l;
                    res={l,r};
                }
            }
        }
    }
    if(mn==LINF) cout<<-1;
    else {
        FORS(i,res.first,res.second) cout<<i<<" ";
    }
}
