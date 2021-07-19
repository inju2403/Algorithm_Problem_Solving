#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int mx;
string res = "(None)";

string solution(string m, vector<string> musicinfos) {
    
    for(auto str: musicinfos) {
        // 1. ,로 파싱
        string cur = "";
        vector<string> v;
        FOR(i,str.size()) {
            if(str[i]==',') {
                v.push_back(cur);
                cur = "";
                continue;
            }
            cur+=str[i];
        }
        v.push_back(cur);
        
        // 2. 시간 차 구하기
        int st = stoi(v[0].substr(0,2))*60 + stoi(v[0].substr(3,2));
        int ed = stoi(v[1].substr(0,2))*60 + stoi(v[1].substr(3,2));
        int diff = abs(ed - st);
        int atcLen = 0;
        for(auto x: v[3]) if(x=='#') atcLen++;
        atcLen = v[3].size() - atcLen;
        
        // 3. 이어 붙이기
        string s = "";
        FOR(i,v[3].size()) s+=v[3][i];
        string tmp = "";
        
        int dv = diff / atcLen;
        
        if(dv > 0) {
            int rem = diff - atcLen*dv;
            if(dv > 1) FOR(i,dv-1) FOR(j,s.size()) v[3]+=s[j];
            FOR(i,rem) {
                if(s[i]=='#') ++rem;
                v[3]+=s[i];
            }
        }
        else {
            int rem = diff;
            FOR(i,rem) {
                if(i+1<s.size() && s[i+1]=='#') ++rem;
                tmp+=s[i];
            }
            v[3] = tmp;
        }
            
        // 4. 전체 비교
        s = v[3];
        FOR(i,s.size()) {
            if(i+m.size()>s.size()) break;
            bool chk = 1;
            FOR(j,m.size()) {
                if(s[i+j]!=m[j]) {
                    chk = 0;
                    break;
                }
                // ABC != ABC# 과 같은 케이스 거르기
                if(j==m.size()-1 && i+j+1<s.size()) {
                    if(s[i+j+1]=='#') {
                        chk=0;
                        break;
                    }
                }
            }
            if(chk) {
                if(mx < diff) {
                    mx = diff;
                    res = v[2];
                }
                break;
            }
        }
    }
    
    return res;
}
