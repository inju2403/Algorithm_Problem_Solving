#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
using namespace std;

int cnt=-1;

string solution(string s) {
    FOR(i,s.size()) {
        if(s[i]==' ') {
            cnt=-1;
            continue;
        }
        ++cnt;
        if(cnt%2==0) {
            if(s[i]>='A' && s[i]<='Z') continue;
            s[i]+='A'-'a';
        }
        else {
            if(s[i]>='a' && s[i]<='z') continue;
            s[i]+='a'-'A';
        }
    }
    return s;
}
