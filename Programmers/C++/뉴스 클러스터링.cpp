#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#define MO 65536
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

double a,b;
vector<string> v1,v2;
unordered_map<string,int> u1,u2,co;

int solution(string str1, string str2) {
    // 전부 대문자로 바꾸기
    FOR(i,str1.size()) if(str1[i]>='a' && str1[i]<='z') str1[i] += 'A'-'a';
    FOR(i,str2.size()) if(str2[i]>='a' && str2[i]<='z') str2[i] += 'A'-'a';
    
    // 알파벳 아닌 문자쌍 버리기
    FOR(i,str1.size()-1) {
        string cur="";
        if(str1[i]>='A' && str1[i]<='Z' && str1[i+1]>='A' && str1[i+1]<='Z') {
            cur+=str1[i];
            cur+=str1[i+1];
            v1.push_back(cur);
        }
    }
    FOR(i,str2.size()-1) {
        string cur="";
        if(str2[i]>='A' && str2[i]<='Z' && str2[i+1]>='A' && str2[i+1]<='Z') {
            cur+=str2[i];
            cur+=str2[i+1];
            v2.push_back(cur);
        }
    }
    
    for(auto x: v1) u1[x]++;
    for(auto x: v2) u2[x]++;
    v1.clear(); v2.clear();
    
    for(auto x: u1) v1.push_back(x.first);
    for(auto x: u2) v2.push_back(x.first);
    
    //교집합 찾기
    FOR(i,v1.size()) {
        FOR(j,v2.size()) {
            string k = v2[j];
            if(v1[i]==k) {
                a += min(u1[k], u2[k]);
                co[k] = max(u1[k], u2[k]);
                break;
            }
        }
    }
    
    //합집합 찾기
    FOR(i,v1.size()) {
        string k = v1[i];
        if(co[k]) b += co[k];
        else b += u1[k];
    }
    FOR(i,v2.size()) {
        string k = v2[i];
        if(!co[k]) b += u2[k];
    }
    
    return a==0&&b==0? MO : (a/b)*MO;
}
