#include <vector>
#include <queue>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 105
using namespace std;

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

struct node {
    int y,x,cost;
};

int n,m;
bool visited[MAX][MAX];

bool isRange(int y, int x) {
    return y>=0 && y<n && x>=0 && x<m;
}

int solution(vector<vector<int> > maps) {
    n = maps.size();
    m = maps[0].size();
    queue<node> q;
    q.push({0,0,0});
    visited[0][0]=1;
    
    while(!q.empty()) {
        int cy = q.front().y;
        int cx = q.front().x;
        int cCost = q.front().cost;
        q.pop();
        
        FOR(dir,4) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(!isRange(ny,nx) || visited[ny][nx] || maps[ny][nx]==0) continue;
            if(ny==n-1 && nx==m-1) return cCost+2;
            visited[ny][nx]=1;
            q.push({ny,nx,cCost+1});
        }
    }
    
    return -1;
}
