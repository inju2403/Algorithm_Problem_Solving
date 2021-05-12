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

int n,m,x,res,inDegree[MAX],d[MAX];
vector<int> t,adj[MAX];

int dp(int cur) {
    int& ret = d[cur];
    if(ret!=-1) return ret;
    if(adj[cur].size()==0) return ret=t[cur];
    
    ret = t[cur];
    int mx = 0;
    for(auto next: adj[cur]) {
        mx = max(mx,dp(next));
    }
    return ret+=mx;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    //1. 시간을 담고 inDegree 세팅
    //2. inDegree가 0인 애들 끼리 max로 돌림
    //3. 탑다운 디피로 값을 구함
    memset(d,-1,sizeof(d));
    cin>>n;
    t.resize(n+1);
    FORS(i,1,n+1) {
        cin>>t[i]>>m;
        while(m--) {
            cin>>x;
            adj[i].push_back(x);
            inDegree[x]++;
        }
    }
    FORS(i,1,n+1) if(!inDegree[i]) res=max(res,dp(i));
    cout<<res;
}
