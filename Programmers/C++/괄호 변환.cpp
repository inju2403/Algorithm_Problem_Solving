#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

string res;

string solution(string p) {
    if(p=="") return "";
    
    int sum = 0;
    string u = "", v = "";
    for(auto x: p) {
        x=='(' ? ++sum : --sum;
        u+=x;
        if(sum==0) break;
    }
    int pSz = p.size();
    int uSz = u.size();
    pSz == uSz? v = "" : v = p.substr(uSz, pSz-uSz);
    
    bool judge = 1;
    for(auto x: u) {
        if(x=='(') ++sum;
        else {
            if(sum==0) {
                judge = 0;
                break;
            }
            else --sum;
        }
    }
    
    if(judge) return u+solution(v);
    
    string cur = "", tmp = "";
    cur = '(' + solution(v) + ')';
    u = u.substr(1,uSz-2);
    for(auto x: u) {
        tmp += x=='(' ? ')' : '(';
    }
    return cur+tmp;
}
