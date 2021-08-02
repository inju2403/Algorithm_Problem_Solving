#include <string>
#include <iostream>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 11
using namespace std;

bool chk[MAX][MAX][MAX][MAX];
int y=5,x=5,res;

bool isRange(int cy,int cx) {
    return cy>=0 && cy<=10 && cx>=0 && cx<=10;
}

int solution(string dirs) {
    for(auto dir: dirs) {
        int cy=y;
        int cx=x;
        if(dir == 'L') {
            --cx;
        } else if(dir=='R') {
            ++cx;
        } else if(dir=='U') {
            ++cy;
        } else if(dir=='D') {
            --cy;
        }
        if(!isRange(cy,cx)) continue;
        if(chk[y][x][cy][cx] || chk[cy][cx][y][x]) {
            y=cy; x=cx;
            continue;
        }
        chk[y][x][cy][cx] = chk[cy][cx][y][x] = 1;
        y=cy; x=cx;
        ++res;
    }
    return res;
}
