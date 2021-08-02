#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int res;

int solution(string skill, vector<string> skill_trees) {
    
    for(auto s: skill_trees) {
        string tmp = "";
        FOR(i,s.size()) {
            for(char c: skill) {
                if(c==s[i]) tmp+=c;
            }
        }
        bool chk = 1;
        FOR(i,tmp.size()) {
            if(tmp[i]!=skill[i]) {
                chk=0;
                break;
            }
        }
        if(chk) ++res;
    }
    
    return res;
}
