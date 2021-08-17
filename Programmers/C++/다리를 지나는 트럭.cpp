#include <string>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int res,sum;
queue<int> q,wait;

int solution(int len, int w, vector<int> t) {
    
    FOR(i,len) q.push(0);
    for(auto x: t) wait.push(x);
    
    while(!q.empty()) {
        ++res;
        sum-=q.front(); q.pop();
        
        if(wait.empty()) {
            res+=q.size();
            break;
        }
        
        int cur = wait.front();
        if(sum+cur > w) q.push(0);
        else {
            q.push(cur);
            sum+=cur; wait.pop();
        }
    }
    
    
    return res;
}
