#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int n,m;
bool judge;

bool isRange(int y, int x) {
    return y>=0 && y<n && x>=0 && x<n;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    n = key.size();
    m = lock.size();
    FOR(rot,4) {
        FORS(addY,-(m-1),n) FORS(addX,-(m-1),n) {
            judge = 1;
            FOR(y,m) {
                FOR(x,m) {
                    int ny = y + addY;
                    int nx = x + addX;
                    if(!isRange(ny,nx)) {
                        if(lock[y][x]==0) {
                            judge = 0;
                            break;
                        }
                    }
                    else if(key[ny][nx] + lock[y][x] != 1) {
                        judge = 0;
                        break;
                    }
                }
                if(judge==0) break;
            }
            if(judge) return true;
        }
        // 배열 돌리기
        vector<vector<int>> tmp(n,vector<int>(n,0));
        FOR(y,n) FOR(x,n) {
            tmp[y][x] = key[(n-1)-x][y];
        }
        FOR(y,n) FOR(x,n) key[y][x] = tmp[y][x];
    }
    
    return false;
}
