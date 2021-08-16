#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int solution(vector<int> c) {
    int res = c.size();
    sort(c.begin(), c.end(),greater<int>());
    FOR(i,c.size()) {
        if(c[i] < i+1) {
            res = i;
            break;
        }
    }
    return res;
}
