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
#define MAX 12
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,m,a,b,mnA=INF,mnB=INF,res,cnt,rem;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    while(m--) {
        cin>>a>>b;
        mnA = min(mnA, a);
        mnB = min(mnB, b);
    }
    cnt = n/6;
    if(!n%6) res = min(mnA*cnt, mnB*n);
    else {
        rem = n - cnt*6;
        res = min({mnA*(cnt+1), mnA*cnt+mnB*rem, mnB*n});
    }
    cout<<res;
}
