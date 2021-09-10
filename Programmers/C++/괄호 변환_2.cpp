#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

bool judge(string k) {
    vector<char> v;
    for(char c: k) {
        if(c=='(') v.push_back(c);
        else {
            if(v.empty()) return false;
            v.pop_back();
        }
    }
    if(v.empty()) return true;
    return false;
}

string solution(string p) {
    
    if(p.empty()) return p;
    string u = "", v = "";
    int cnt = 0;
    FOR(i,p.size()) {
        char c = p[i];
        if(c=='(') ++cnt;
        else --cnt;
        if(cnt==0) {
            u = p.substr(0,i+1);
            v = p.substr(i+1);
            break;
        }
    }
    if(judge(u)) return u+solution(v);
    
    string res = "(" + solution(v) + ")";
    FORS(i,1,u.size()-1) {
        if(u[i]=='(') res+=')';
        else res+='(';
    }
    
    return res;
}
