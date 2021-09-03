#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
using namespace std;

int mx=-INF,mn=INF;

string solution(string s) {
    string num = "";
    FOR(i,s.size()) {
        if(s[i]==' ') {
            int n = stoi(num);
            mx=max(mx,n);
            mn=min(mn,n);
            num="";
            continue;
        }
        num+=s[i];
    }
    int n = stoi(num);
    mx=max(mx,n);
    mn=min(mn,n);
    return to_string(mn)+" "+to_string(mx);
}
