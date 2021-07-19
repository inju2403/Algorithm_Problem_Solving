#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 35

using namespace std;

const int dy[] = {0,1,1};
const int dx[] = {1,0,1};

//0: 빈칸
int res,mp[MAX][MAX];
bool judge=1,chk[MAX][MAX];

int solution(int m, int n, vector<string> board) {
    FOR(y,m) {
        string s = board[y];
        FOR(x,n) mp[y][x] = s[x]-'A'+1;
    }
    
    while(judge) {
        judge=0;
        memset(chk,0,sizeof(chk));
        
        //1. 터트릴 애들 체크
        FOR(y, m-1) FOR(x, n-1) {
            int cur = mp[y][x];
            if(cur == 0) continue;
            bool c = 1;
            FOR(dir,3) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                int next = mp[ny][nx];
                if(cur!=next) {
                    c=0;
                    break;
                }
            }
            if(c) {
                judge = 1;
                chk[y][x]=chk[y+1][x]=chk[y][x+1]=chk[y+1][x+1]=1;
            }
        }
        
        //2. 터트림 -> 값을 0으로 바꿈
        FOR(y,m) FOR(x,n) if(chk[y][x]) mp[y][x]=0, ++res;
        
        //3. 떨어뜨림
        FOR(x,n) {
            for(int y=m-2; y>=0; --y) {
                int& cur = mp[y][x];
                if(cur==0) continue;
                for(int ny=m-1; ny>y; --ny) {
                    int& next = mp[ny][x];
                    if(next==0) {
                        next = cur;
                        cur = 0;
                    }
                }
            }
        }
    }
    
    return res;
}
