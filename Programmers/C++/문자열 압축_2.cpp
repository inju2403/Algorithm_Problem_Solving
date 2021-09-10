#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321

using namespace std;

int mn=INF,cnt;

int solution(string s) {
    int sz = s.size();
    if(s.size()==1) return 1;
    
    FORS(i,1,sz/2+1) {
        string res = "";
        string cur = s.substr(0,i);
        cnt = 1;
        for(int j=i; j<sz; j+=i) {
            string next = s.substr(j,i);
            if(cur==next) ++cnt;
            else {
                if(cnt>1) res += to_string(cnt) + cur;
                else res += cur;
                cur = next;
                cnt = 1;
            }
        }
        if(cnt>1) res += to_string(cnt) + cur;
        else res += cur;
        int curSz = res.size();
        if(mn > curSz) {
            mn = curSz;
        }
    }
    
    return mn;
}
