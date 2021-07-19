#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int mx;
string res = "(None)";

void replaceAll(string& s, string from, string to) {
    int pos = 0;
    while(1) {
        pos = s.find(from);
        if(pos==-1) break;
        s.replace(pos, from.length(), to);
    }
}

string solution(string m, vector<string> musicinfos) {
    
    // 0. m의 # 치환
    replaceAll(m, "A#", "a");
    replaceAll(m, "C#", "c");
    replaceAll(m, "D#", "d");
    replaceAll(m, "F#", "f");
    replaceAll(m, "G#", "g");
    
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
        
        // 2. musicinfos의 # 치환
        replaceAll(v[3], "A#", "a");
        replaceAll(v[3], "C#", "c");
        replaceAll(v[3], "D#", "d");
        replaceAll(v[3], "F#", "f");
        replaceAll(v[3], "G#", "g");
        
        // 3. 시간 차 구하기
        int st = stoi(v[0].substr(0,2))*60 + stoi(v[0].substr(3,2));
        int ed = stoi(v[1].substr(0,2))*60 + stoi(v[1].substr(3,2));
        int diff = abs(ed - st);
        
        // 4. 이어 붙이기
        string s = "";
        for(auto x: v[3]) s+=x;
        
        int dv = diff / s.size();
        int rem= diff - s.size()*dv;
        if(dv>=1) {
            if(dv>1) FOR(i,dv-1) FOR(j,s.size()) v[3]+=s[j];
            FOR(i,rem) v[3]+=s[i];
        }
        else {
            FOR(i,s.size()-rem) v[3].pop_back();
        }
        
        // 5. 전체 비교
        s = v[3];
        FOR(i,s.size()) {
            if(i+m.size()>s.size()) break;
            bool chk = 1;
            FOR(j,m.size()) {
                if(s[i+j]!=m[j]) {
                    chk=0;
                    break;
                }
            }
            if(chk) {
                if(mx < diff) {
                    mx = diff;
                    res = v[2];
                }
            }
        }
    }
    
    return res;
}
