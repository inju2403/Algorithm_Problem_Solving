#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define LINF 9123456789123456789
#define MAX 110
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

int n,m,k,a,b,res,mp[MAX][MAX];
bool visited[MAX][MAX];

struct node {
    int y,x,cnt;
};

bool isRange(int y,int x) {
    return y>=0 && y<n && x>=0 && x<m;
}

int dfs(int y, int x) {
    int ret = 1;
    FOR(dir,4) {
        int ny = y+dy[dir];
        int nx = x+dx[dir];
        if(isRange(ny,nx) && mp[ny][nx] && !visited[ny][nx]) {
            visited[ny][nx]=1;
            ret += dfs(ny,nx);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>k;
    while(k--) {
        cin>>a>>b;
        mp[a-1][b-1]=1;
    }
    FOR(y,n) FOR(x,m) if(!visited[y][x] && mp[y][x]) {
        visited[y][x]=1;
        res=max(res,dfs(y,x));
    }
    cout<<res;
}
