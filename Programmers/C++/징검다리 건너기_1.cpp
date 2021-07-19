#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
using namespace std;

int l=INF,r,pos,mx,res;
vector<int> v;

int solution(vector<int> stones, int k) {
    for(auto x: stones) {
        l=min(l,x);
        r=max(r,x);
    }
    l--; r++;
    while(l<=r) {
        v.clear(); pos=-1; mx=0;
        for(auto x: stones) v.push_back(x);
        int mid=(l+r)/2;
        FOR(i,v.size()) {
            v[i]-=mid;
            if(v[i]<0) v[i]=0;
        }
        FOR(i,v.size()) {
            if(v[i]==0) continue;
            if(pos==-1) pos=i, mx=i+1;
            else {
                mx=max(mx,i-pos);
                pos=i;
            }
        }
        mx=max(mx,(int)v.size()-pos);
        if(mx>k) r=mid-1;
        else {
            res=max(res,mid);
            l=mid+1;
        }
    }
    return res+1;
}
