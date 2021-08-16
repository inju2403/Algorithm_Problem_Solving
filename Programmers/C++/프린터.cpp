#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;
typedef pair<int,int> pii;

int i,mx,cnt=1,res;
queue<int> mxQ;
queue<pii> q;

int solution(vector<int> p, int l) {
    for(auto x: p) q.push({x,i++});
    sort(p.begin(),p.end(),greater<int>());
    for(auto x: p) mxQ.push(x);
    mx = mxQ.front(); mxQ.pop();
    
    while(1) {
        pii cur = q.front(); q.pop();
        if(cur.first==mx) {
            if(cur.second == l) {
                res = cnt;
                break;
            }
            mx = mxQ.front(); mxQ.pop();
            ++cnt;
        }
        else q.push(cur);
    }
    return res;
}
