#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
using namespace std;

int res,idx=1;
unordered_map<string, int> um;

int solution(int cacheSize, vector<string> cities) {
    
    if(cacheSize==0) return cities.size()*5;
    
    //전부 대문자로 변경
    for(auto& s: cities) {
        FOR(i,s.size()) if(s[i]>='a' && s[i]<='z') s[i]+='A'-'a';
    }
    
    for(auto x: cities) {
        int sz = um.size();
        if(sz < cacheSize) {
            if(um[x]) res+=1; // hit
            else res+=5; // miss
        }
        else {
            auto item = um.find(x);
            if(item != um.end()) res+=1; // hit
            else { // miss
                int mn = INF; string s = "";
                for(auto u: um) {
                    if(mn > u.second) {
                        mn = u.second;
                        s = u.first;
                    }
                }
                um.erase(s);
                res+=5;
            }
        }
        um[x]=idx++;
    }
    return res;
}
