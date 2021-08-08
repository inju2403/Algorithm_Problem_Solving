#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
using namespace std;

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

vector<vector<int>> mp;

struct node {
    int y,x,cnt;
};

bool isRange(int y,int x) {
    return y>=0 && y<4 && x>=0 && x<4;
}

int bfs(node src, node sink) {
    int ret = INF;
    bool visited[4][4] = {0,};
    queue<node> q;
    q.push(src);
    visited[src.y][src.x]=1;
    while(!q.empty()) {
        node cur = q.front();
        q.pop();
        if(cur.y==sink.y && cur.x==sink.x) return cur.cnt;
        
        // 방향키 1칸
        FOR(dir,4) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if(!isRange(ny,nx) || visited[ny][nx]) continue;
            visited[ny][nx]=1;
            q.push({ny,nx,cur.cnt+1});
        }
        
        // ctrl+방향키
        FOR(dir,4) {
            int ny = cur.y;
            int nx = cur.x;
            while(1) {
                ny += dy[dir];
                nx += dx[dir];
                if(!isRange(ny,nx)) {
                    ny -= dy[dir];
                    nx -= dx[dir];
                    break;
                }
                if(mp[ny][nx]) break;
            }
            if(!isRange(ny,nx) || visited[ny][nx]) continue;
            visited[ny][nx]=1;
            q.push({ny,nx,cur.cnt+1});
        }
    }
    
    return ret;
}

int go(node src) {
    int ret = INF;
    
    FORS(i,1,7) {
        vector<node> v;
        FOR(y,4) FOR(x,4) {
            if(mp[y][x]==i) v.push_back({y,x,0});
        }
        if(v.empty()) continue;
        
        int a = bfs(src,v[0]) + bfs(v[0],v[1]) + 2; //엔터 2번 더해줌
        int b = bfs(src,v[1]) + bfs(v[1],v[0]) + 2;
        
        mp[v[0].y][v[0].x] = 0;
        mp[v[1].y][v[1].x] = 0;
        
        ret = min(ret, a + go(v[1]));
        ret = min(ret, b + go(v[0]));
        
        mp[v[0].y][v[0].x] = i;
        mp[v[1].y][v[1].x] = i;
    }
    
    return ret==INF? 0 : ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    mp = board;
    return go({r,c,0});
}
