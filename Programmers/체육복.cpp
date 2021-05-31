#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
using namespace std;

bool chk[31],excpt[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int res = lost.size();
    for(auto next: reserve) chk[next]=1;
    for(auto next: lost) if(chk[next]) chk[next]=0, excpt[next]=1, --res;
    for(auto next: lost) {
        if(excpt[next]) continue;
        if(chk[next-1]) {
            chk[next-1]=0;
            --res;
        }
        else if(chk[next+1]) {
            chk[next+1]=0;
            --res;
        }
    }
    return n-res;
}
