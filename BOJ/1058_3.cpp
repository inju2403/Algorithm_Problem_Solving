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
#define INF 987654321
#define MAX 51
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,res,adj[MAX][MAX];
string s[MAX];

void floyd() {
    FOR(k,n) FOR(i,n) FOR(j,n) {
        if(adj[i][j]>adj[i][k]+adj[k][j]) adj[i][j]=adj[i][k]+adj[k][j];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    FOR(i,n) cin>>s[i];
    FOR(i,n) FOR(j,n) {
        if(i==j) adj[i][j] = 0;
        else adj[i][j] = s[i][j]=='Y'? 1 : INF;
    }
    floyd();
    FOR(i,n) {
        int sum=0;
        FOR(j,n) {
            if(adj[i][j]==1 || adj[i][j]==2) ++sum;
        }
        res=max(res,sum);
    }
    cout<<res;
}
