#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int num,idx;
string s;
unordered_map<string,int> um;

vector<int> solution(string msg) {
    vector<int> res;
    
    // 1
    FOR(i,26) {
        s = "";
        s+='A'+num++;
        um[s]=num;
    }
    bool chk = 1;
    while(idx<msg.size()) {
        FORS(i,idx,msg.size()) {
            string s = "";
            // 2
            chk = 1;
            FORS(j,i,msg.size()) {
                s+=msg[j];
                if(um.count(s)) continue;
                
                // 4
                um[s]=++num;
                
                // 3
                idx=j;
                s.pop_back();
                res.push_back(um[s]);
                chk = 0;
                break;
            }
            if(chk) res.push_back(um[s]);
            break;
        }
        if(chk) break;
    }
    
    return res;
}
