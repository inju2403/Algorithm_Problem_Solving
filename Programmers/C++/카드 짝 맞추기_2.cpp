#include <iostream>
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

int res = INF;
vector<vector<int>> mp, ori;

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

int go(node root, vector<int>& p) {
    int ret = INF;
    node src = root;
    FOR(t,1<<6) {
        int cur = 0;
        src = root;
        mp = ori;
        for(int num: p) {
            vector<node> v;
            FOR(y,4) FOR(x,4) if(mp[y][x]==num) v.push_back({y,x,0});
            if(v.empty()) continue;
            
            int k = 1<<(num-1);
            if((t & k) == k) {
                cur += bfs(src, v[0]) + bfs(v[0], v[1]) + 2;
                src = v[1];
            } else {
                cur += bfs(src, v[1]) + bfs(v[1], v[0]) + 2;
                src = v[0];
            }
            
            mp[v[0].y][v[0].x] = 0;
            mp[v[1].y][v[1].x] = 0;
        }
        ret = min(ret,cur);
    }
    return ret==INF? 0 : ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    mp = board;
    ori = board;
    vector<int> p;
    FORS(i,1,7) p.push_back(i);
    node root = {r,c,0};
    do {
        res = min(res, go(root,p));
    } while(next_permutation(p.begin(), p.end()));
    
    return res;
}
