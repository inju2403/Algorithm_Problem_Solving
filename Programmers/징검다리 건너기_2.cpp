#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
using namespace std;

int l=INF,r,cnt,res;
bool chk;

int solution(vector<int> stones, int k) {
    for(auto x: stones) {
        l=min(l,x);
        r=max(r,x);
    }
    while(l<=r) {
        cnt=0; chk=1;
        int mid=(l+r)/2;
        for(auto x: stones) {
            if(x<mid) ++cnt;
            else cnt=0;
            
            if(cnt==k) {
                chk=0;
                break;
            }
        }
        if(chk) {
            l=mid+1;
            res=max(res,mid);
        }
        else r=mid-1;
    }
    return res;
}
