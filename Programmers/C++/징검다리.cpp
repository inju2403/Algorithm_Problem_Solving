#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int res;

int solution(int distance, vector<int> rocks, int n) {
    
    rocks.push_back(0);
    rocks.push_back(distance);
    
    sort(rocks.begin(), rocks.end());
    
    int l=1, r=distance;
    
    while(l<=r) {
        int mid = (l+r)/2;
        int idx = 0, cnt = 0;
        FORS(i,1,rocks.size()) {
            if(rocks[i]-rocks[idx] < mid) ++cnt;
            else idx = i;
        }
        if(cnt<=n) {
            l = mid + 1;
            res = max(res,mid);
        }
        else r = mid - 1;
    }
    
    return res;
}
