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
#define LINF 2123456789123456789
#define V_MAX 50005
#define EDGE_MAX 200005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int tc,res,mp[3][3],ori[3][3];
bool visited[8];
char c;

void go(int dir,int cnt) {
    bool judge=1;
    FOR(y,3) FOR(x,3) if(mp[0][0]!=mp[y][x]) {
        judge=0;
        break;
    }
    if(judge) {
        res=min(res,cnt);
        return;
    }
    
    switch(dir) {
        case 0:
            FOR(x,3) mp[0][x]=!mp[0][x];
        break;
        case 1:
            FOR(x,3) mp[1][x]=!mp[1][x];
        break;
        case 2:
            FOR(x,3) mp[2][x]=!mp[2][x];
        break;
        case 3:
            FOR(y,3) mp[y][0]=!mp[y][0];
        break;
        case 4:
            FOR(y,3) mp[y][1]=!mp[y][1];
        break;
        case 5:
            FOR(y,3) mp[y][2]=!mp[y][2];
        break;
        case 6:
            FOR(k,3) mp[k][k]=!mp[k][k];
        break;
        case 7:
            FOR(k,3) mp[k][2-k]=!mp[k][2-k];
        break;
    }
    
    int tmp[3][3];
    FOR(y,3) FOR(x,3) tmp[y][x]=mp[y][x];
    
    
    FOR(i,8) {
        if(visited[i]) continue;
        visited[i]=1;
        go(i,cnt+1);
        visited[i]=0;
        FOR(y,3) FOR(x,3) mp[y][x]=tmp[y][x];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        memset(mp,0,sizeof(mp));
        memset(visited,0,sizeof(visited));
        res=INF;
        FOR(y,3) FOR(x,3) {
            cin>>c;
            if(c=='H') mp[y][x]=1;
        }
        FOR(y,3) FOR(x,3) ori[y][x]=mp[y][x];
        
        FOR(i,8) {
            visited[i]=1;
            go(i,0);
            visited[i]=0;
            FOR(y,3) FOR(x,3) mp[y][x]=ori[y][x];
        }
        cout<<(res==INF? -1 : res)<<'\n';
    }
}
