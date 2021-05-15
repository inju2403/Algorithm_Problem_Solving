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

int n,k,b,x,res=INF;
vector<int> sum;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k>>b;
    sum.resize(n+1);
    while(b--) {
        cin>>x;
        sum[x]=1;
    }
    FORS(i,1,n) sum[i+1]+=sum[i];
    FORS(i,1,n+1) {
        if(i+k>n) break;
        res=min(res,sum[i+k]-sum[i]);
    }
    cout<<res;
}
