#include <iostream>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int res,mx;

int solution(vector<vector<int> > land) {
    FORS(y,1,land.size()) {
        FOR(x,land[0].size()) {
            int mx = 0;
            FOR(px,land[0].size()) {
                if(x==px) continue;
                mx = max(mx,land[y-1][px]);
            }
            land[y][x]+=mx;
        }
    }

    FOR(x,land[0].size()) res=max(res,land[land.size()-1][x]);
    return res;
}
