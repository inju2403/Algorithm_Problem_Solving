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
#define MAX 501
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

int n,m,mx,res,mp[MAX][MAX];
bool visited[MAX][MAX];

bool judge(int y,int x) {
    return y>=0 && y<n && x>=0 && x<m;
}

int dfs(int y,int x) {
    int ret=1;
    FOR(dir,4) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(!judge(ny,nx) || visited[ny][nx] || !mp[ny][nx]) continue;
        visited[ny][nx]=1;
        ret+=dfs(ny,nx);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    FOR(y,n) FOR(x,m) cin>>mp[y][x];
    FOR(y,n) FOR(x,m) {
        if(visited[y][x] || !mp[y][x]) continue;
        visited[y][x]=1;
        mx=max(mx,dfs(y,x));
        ++res;
    }
    cout<<res<<'\n'<<mx;
}
