#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;
vector<int> res;

vector<int> solution(int brown, int yellow) {
    
    for(int y=1; y*y<=yellow; ++y) {
        if(yellow%y) continue;
        int x = yellow / y;
        int i = 1;
        while((x+2*i)*(y+2*i) <= brown+yellow) {
            if((x+2*i)*(y+2*i) == brown+yellow) {
                res.push_back(x+2*i);
                res.push_back(y+2*i);
                return res;
            }
            ++i;
        }
    }
    
    return res;
}
