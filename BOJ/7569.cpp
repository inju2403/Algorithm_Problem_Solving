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
#define MAX 101
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int dy[] = {-1,1,0,0,0,0};
const int dx[] = {0,0,-1,1,0,0};
const int dz[] = {0,0,0,0,-1,1};

struct node {
    int y,x,z;
};

int n,m,h,cnt,sum,res,mp[MAX][MAX][MAX];
queue<node> q;

bool isRange(int y,int x,int z) {
    return y>=0 && y<n && x>=0 && x<m && z>=0 && z<h;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>m>>n>>h;
    FOR(z,h) FOR(y,n) FOR(x,m) {
        cin>>mp[y][x][z];
        if(mp[y][x][z]==1) q.push({y,x,z});
        else if(mp[y][x][z]==0) ++sum;
    }
    if(sum==0) {
        cout<<0;
        return 0;
    }
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int cy = q.front().y;
            int cx = q.front().x;
            int cz = q.front().z;
            q.pop();
            
            FOR(dir,6) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                int nz = cz + dz[dir];
                
                if(!isRange(ny, nx, nz) || mp[ny][nx][nz]==1 || mp[ny][nx][nz]==-1) continue;
                q.push({ny,nx,nz});
                mp[ny][nx][nz]=1;
                ++cnt;
            }
        }
        ++res;
        if(sum==cnt) break;
    }
    FOR(z,h) FOR(y,n) FOR(x,m) {
        if(mp[y][x][z]==0) {
            cout<<-1;
            return 0;
        }
    }
    cout<<res;
}
