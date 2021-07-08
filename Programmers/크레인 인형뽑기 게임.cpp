#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
using namespace std;

vector<int> basket;
vector<vector<int>> mp;
int res;

int solution(vector<vector<int>> board, vector<int> moves) {
    int sz = board.size();
    mp.resize(sz);
    FOR(x,sz) {
        for(int y=sz-1;y>=0;--y) if(board[y][x]) mp[x].push_back(board[y][x]);
    }
    FOR(i,moves.size()) {
        int k = moves[i]-1;
        if(basket.empty()) {
            basket.push_back(mp[k].back());
            mp[k].pop_back();
        }
        else {
            if(basket.back()==mp[k].back()) {
                res+=2;
                basket.pop_back();
            }
            else {
                basket.push_back(mp[k].back());
            }
            mp[k].pop_back();
        }
    }
    return res;
}
