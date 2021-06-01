#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int solution(int left, int right) {
    int res = 0;
    FORS(i,left,right+1) {
        int cnt=0;
        FORS(j,1,i+1) if(i%j==0) ++cnt;
        cnt%2? res-=i : res+=i;
    }
    return res;
}
