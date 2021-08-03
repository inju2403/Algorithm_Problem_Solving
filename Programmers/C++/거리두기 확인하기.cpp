#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

bool judge,visited[5][5];
vector<int> res;

bool isRange(int y,int x) {
    return y>=0 && y<5 && x>=0 && x<5;
}

void dfs(int y,int x,vector<string> mp,int depth) {
    if(depth>2 || judge==0) return;
    if(depth>0 && mp[y][x]=='P') {
        judge = 0;
        return;
    }
    visited[y][x]=1;
    FOR(dir,4) {
        int ny = y+dy[dir];
        int nx = x+dx[dir];
        if(!isRange(ny,nx) || visited[ny][nx] || mp[ny][nx]=='X') continue;
        dfs(ny,nx,mp,depth+1);
    }
}

vector<int> solution(vector<vector<string>> places) {
    
    for(auto mp: places) {
        judge = 1;
        FOR(y,5) {
            FOR(x,5) {
                if(mp[y][x]=='P') {
                    memset(visited,0,sizeof(visited));
                    dfs(y,x,mp,0);
                    if(judge==0) break;
                }
            }
            if(judge==0) break;
        }
        if(judge) res.push_back(1);
        else res.push_back(0);
    }
    
    return res;
}
