#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 30
#define INF 987654321
using namespace std;

const int dy[]={-1,1,0,0};
const int dx[]={0,0,-1,1};

int n,mp[MAX][MAX],dp[MAX][MAX][4];

bool isRange(int y,int x) {
    return y>=0 && y<n && x>=0 && x<n;
}

struct node {
    int y,x,dir;
    bool operator < (const node& arg) const {
        return dir < arg.dir;
    }
};

int dijkstra() {

    priority_queue<pair<int,node>> pq;
    pq.push({0,{0,0,0}});
    pq.push({0,{0,0,1}});
    pq.push({0,{0,0,2}});
    pq.push({0,{0,0,3}});
    
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cy = pq.top().second.y;
        int cx = pq.top().second.x;
        int d = pq.top().second.dir;
        pq.pop();
        
        if(cost>dp[cy][cx][d]) continue;
        
        FOR(dir,4) {
            int ny=cy+dy[dir];
            int nx=cx+dx[dir];
            if(!isRange(ny,nx)) continue;
            if(mp[ny][nx]==1) continue;
            
            int nextCost = cost;
            if(d==dir) nextCost+=100;
            else nextCost+=600;
            
            if(dp[ny][nx][dir] > nextCost) {
                dp[ny][nx][dir] = nextCost;
                pq.push({-nextCost,{ny,nx,dir}});
            }
        }
    }
    return min({dp[n-1][n-1][0],dp[n-1][n-1][1],dp[n-1][n-1][2],dp[n-1][n-1][3]});
}

int solution(vector<vector<int>> board) {
    n=board.size();
    FOR(i,n) FOR(j,n) mp[i][j]=board[i][j];
    FOR(i,n) FOR(j,n) FOR(k,4) dp[i][j][k]=INF;
    
    return dijkstra();
}
