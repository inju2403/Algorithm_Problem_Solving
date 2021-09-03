#include <string>
#include <vector>

using namespace std;

int res,ori,cnt;

int solution(int n) {
    ori = n;
    while(n) {
        cnt+=n%2;
        n/=2;
    }
    
    res=ori+1;
    while(res<1e6+1) {
        int k = res;
        int c = 0;
        while(k) {
            c+=k%2;
            k/=2;
        }
        if(cnt==c) return res;
        ++res;
    }
    return res;
}
