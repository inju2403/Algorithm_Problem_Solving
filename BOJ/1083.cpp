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

int n,s,mx,mxIdx;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    v.resize(n);
    FOR(i,n) cin>>v[i];
    cin>>s;
    FOR(i,n) {
        mx=v[i];
        mxIdx=i;
        for(int j=i+1; j<min(n,s+i+1);++j) {
            if(mx<v[j]) {
                mx=v[j];
                mxIdx=j;
            }
        }
        rotate(v.begin()+i, v.begin()+mxIdx, v.begin()+mxIdx+1);
        s-=mxIdx-i;
        if(!s) break;
    }
    FOR(i,n) cout<<v[i]<<" ";
}
