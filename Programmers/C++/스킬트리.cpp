#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int res,idx;
unordered_map<char, bool> um;

int solution(string skill, vector<string> skill_trees) {
    
    for(auto s: skill_trees) {
        idx=-1;
        bool chk = 1;
        um.clear();
        for(char c: skill) {
            FOR(i,s.size()) {
                if(c==s[i]) {
                    if(idx>i) {
                        chk=0;
                        break;
                    }
                    um[c]=1;
                    idx=i;
                }
            }
            if(!chk) break;
        }
        if(chk) {
            int judge=0;
            for(int i=skill.size();i>=0; --i) {
                if(um.count(skill[i])==1) {
                    judge=1;
                }
                else {
                    if(judge==1) {
                        judge=-1;
                        break;
                    }
                }
            }
            if(judge!=-1) ++res;
        }
    }
    
    return res;
}
