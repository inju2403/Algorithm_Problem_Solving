#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321

using namespace std;

int res = INF;

int solution(int n, vector<int> weak, vector<int> dist) {
    int w = weak.size();
    FOR(i,w) weak.push_back(n+weak[i]);
    sort(dist.begin(), dist.end());
    
    do {
        FOR(i, w) {
            int st = weak[i];
            int ed = weak[i+w-1];
            
            FOR(j, dist.size()) {
                st += dist[j];
                if(st>=ed) {
                    res = min(res, j+1);
                    break;
                }
                int next = j+1;
                while(weak[next]<=st) ++next;
                st = weak[next];
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
        
    return res==INF? -1 : res;
}
