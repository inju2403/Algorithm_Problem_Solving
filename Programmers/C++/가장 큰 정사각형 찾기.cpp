#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int mx;

int solution(vector<vector<int>> board) {
    int ySz = board.size();
    int xSz = board[0].size();
    FOR(y,ySz) FOR(x,xSz) mx=max(mx,board[y][x]);
    FORS(y,1,ySz) FORS(x,1,xSz) {
        if(board[y][x]!=0) {
            board[y][x] = min({board[y-1][x-1],board[y-1][x],board[y][x-1]})+1;
            mx = max(mx,board[y][x]);
        }
    }
    
    return mx*mx;
}
