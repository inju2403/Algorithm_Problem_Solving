#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int res,l,r;

int solution(vector<int> p, int limit) {
    sort(p.begin(), p.end());
    
    l = 0; r = p.size()-1;
    while(l<=r) {
        if(p[l]+p[r]<=limit) {
            ++l;
            --r;
        }
        else --r;
        ++res;
    }
    
    return res;
}
