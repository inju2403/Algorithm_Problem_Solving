#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 30

using namespace std;
typedef pair<int,int> pii;

//반대방향 (dir+2)%4 -> 다음 방향에서 제외한다.
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int n,cost[MAX][MAX][4];

struct node {
    int cost,dir,y,x;
    bool operator < (const node& arg) const {
        return cost<arg.cost;
    }
};

bool isRange(int y,int x) {
    return y>=0 && y<n && x>=0 && x<n;
}

int dijkstra(vector<vector<int>> mp) {
    FOR(i,4) cost[0][0][i]=0;
    
    priority_queue<node> pq;
    FOR(dir,4) pq.push({0,dir,0,0});
    
    while(!pq.empty()) {
        int curCost = pq.top().cost;
        int curDir = pq.top().dir;
        int cy = pq.top().y;
        int cx = pq.top().x;
        pq.pop();
        
        if(curCost > cost[cy][cx][curDir]) continue;
        
        FOR(dir,4) {
            if(dir == (curDir+2)%4) continue; // 반대방향으로는 이동x
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(!isRange(ny,nx)) continue;
            if(mp[ny][nx]==1) continue;
            
            int nextCost = 0;
            if(dir == curDir) nextCost = curCost + 100;
            else nextCost = curCost + 600;
            if(cost[ny][nx][dir] > nextCost) {
                cost[ny][nx][dir] = nextCost;
                pq.push({nextCost,dir,ny,nx});
            }
        }
    }
    return min({cost[n-1][n-1][0],cost[n-1][n-1][1],cost[n-1][n-1][2],cost[n-1][n-1][3]});
}

int solution(vector<vector<int>> board) {
    n=board.size();
    FOR(i,n) FOR(j,n) FOR(k,4) cost[i][j][k]=INF;
    return dijkstra(board);
}
