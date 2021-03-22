#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,mx,res,mxTmp;
vector<int> tmp;
vector<vector<int>> v;

void dfs(vector<int> a, int num, int idx) {
    if(a.size()==3) {
        int sum = a[0]+a[1]+a[2];
        mxTmp=max(mxTmp, sum % 10);
        return;
    }
    FORS(i, idx, 5) {
        a.push_back(v[num][i]);
        dfs(a,num,i+1);
        a.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    v.resize(n);
    FOR(i,n) {
        v[i].resize(5);
        FOR(j,5) cin>>v[i][j];
        tmp.clear(); mxTmp = 0;
        dfs(tmp, i, 0);
        if(mx<=mxTmp) {
            mx=mxTmp;
            res=i+1;
        }
    }
    cout<<res;
}
