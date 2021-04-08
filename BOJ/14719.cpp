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

int h,w,mxL,mxR,res;
vector<int> v;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>h>>w;
    v.resize(w);
    FOR(i,w) cin>>v[i];
    FORS(i,1,w) {
        mxL=mxR=v[i];
        //to the left
        for(int j=i-1; j>=0; --j) mxL=max(mxL,v[j]);
        //to the right
        FORS(j,i+1,w) mxR=max(mxR,v[j]);
        res+=min(mxL,mxR)-v[i];
    }
    cout<<res;
}
