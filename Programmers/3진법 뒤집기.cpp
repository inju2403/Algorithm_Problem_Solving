#include <string>
#include <vector>
#include <string>
#define FOR(i,n) for(int i=0;i<(n);++i)

using namespace std;

vector<int> v;

int fun(int x) {
    int ret=1;
    FOR(i,x) ret*=3;
    return ret;
}

int solution(int n) {
    int res = 0;
    while(n) {
        v.push_back(n%3);
        n/=3;
    }
    FOR(i,v.size()) res+=v[i]*fun(v.size()-1-i);
    return res;
}
