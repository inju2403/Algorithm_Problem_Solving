#include <iostream>
#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int n,kSz;

bool isRange(int y,int x) {
    return y>=0 && y<kSz && x>=0 && x<kSz;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    n = lock.size();
    kSz = key.size();
    
    FOR(rot, 4) {
        bool flag = 1;
        for(int py = kSz-1; py >= -(n-1); --py) {
            for(int px = kSz-1; px >= -(n-1); --px) {
                flag = 1;
                FOR(y,n) FOR(x,n) {
                    int kny = y+py;
                    int knx = x+px;
                    if(!isRange(kny,knx)) {
                        if(lock[y][x]==0) flag = 0;
                    }
                    else if(key[kny][knx]+lock[y][x] != 1) {
                        flag = 0;
                    }
                }
                if(flag) return true;
            }
        }
        // 시계 방향으로 90도 회전
        vector<vector<int>> tmp(kSz, vector<int>(kSz,n));
        FOR(ky,kSz) FOR(kx,kSz) {
            tmp[kx][(kSz-1)-ky] = key[ky][kx];
        }
        FOR(ky,kSz) FOR(kx,kSz) {
            key[ky][kx] = tmp[ky][kx];
        }
    }
    return false;
}
