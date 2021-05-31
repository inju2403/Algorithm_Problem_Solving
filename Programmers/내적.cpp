#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int res = 0;
    FOR(i,a.size()) res+=a[i]*b[i];
    return res;
}
