#include <string>
#include <vector>
using namespace std;

string res;
bool chk = 0;

string solution(string number, int k) {
    for(char c: number) {
        if(chk) {
            res+=c;
            continue;
        }
        if(res.empty()) res+=c;
        else {
            while(!res.empty() && res[res.size()-1]-'0' < c-'0' && k) {
                --k;
                res.pop_back();
            }
            res+=c;
            if(!k) chk = 1;
        }
    }
    while(k--) res.pop_back();
    return res;
}
