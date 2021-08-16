#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

vector<int> res;

vector<int> solution(vector<int> p, vector<int> s) {
    
    int cnt = 1;
    int day = (100-p[0])/s[0];
    if((100-p[0])%s[0]!=0) day++;
    
    FORS(i,1,p.size()) {
        int next = (100-p[i])/s[i];
        if((100-p[i])%s[i]!=0) next++;
        
        if(day >= next) ++cnt;
        else {
            res.push_back(cnt);
            cnt = 1;
            day = next;
        }
    }
    res.push_back(cnt);
    
    return res;
}
