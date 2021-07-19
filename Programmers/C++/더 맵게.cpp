#include <string>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;
int cnt;
priority_queue<int> pq;

int solution(vector<int> scoville, int K) {
    for(auto x: scoville) pq.push(-x);
    while(!pq.empty()) {
        int a = -pq.top();
        if(a>=K) return cnt;
        pq.pop();
        if(pq.empty()) return -1;
        int b = -pq.top(); pq.pop();
        
        pq.push(-(a+2*b));
        ++cnt;
    }
    return -1;
}
