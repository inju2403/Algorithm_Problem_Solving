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

int n,k,l,r,res=INF;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    l=0, r=k;
    while(l<=r) {
        ll cnt=0;
        int mid=(l+r)/2;
        FORS(i,1,n+1) cnt+=min(mid/i,n);
        if(cnt>=k) {
            res=min(res,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<res;
}
