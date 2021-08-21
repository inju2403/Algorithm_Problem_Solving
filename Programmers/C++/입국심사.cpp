#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define LINF 9123456789123456789

using namespace std;
typedef long long ll;

ll res=LINF,l,r;

long long solution(int n, vector<int> times) {
    
    for(ll x: times) r=max(r,x);
    r*=n;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll sum = 0;
        for(int x: times) {
            sum += mid/x;
        }
        if(sum>=n) {
            res = min(res,mid);
            r = mid-1;
        }
        else l = mid+1;
    }
    
    return res;
}
