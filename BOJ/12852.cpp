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
#define MAX 1000001
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,pre[MAX],cache[MAX];

int dp(int x) {
    if(x==1) return 0;
    
    int& ret = cache[x];
    if(ret!=-1) return ret;
    
    ret=INF;
    if(x%3==0) {
        if(ret > dp(x/3)+1) {
            ret = dp(x/3)+1;
            pre[x]=x/3;
        }
    }
    if(x%2==0) {
        if(ret > dp(x/2)+1) {
            ret = dp(x/2)+1;
            pre[x]=x/2;
        }
    }
    if(x%6!=0) {
        if(ret > dp(x-1)+1) {
            ret = dp(x-1)+1;
            pre[x]=x-1;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>n;
    cout<<dp(n)<<'\n';
    while(n) {
        cout<<n<<" ";
        n=pre[n];
    }
}
