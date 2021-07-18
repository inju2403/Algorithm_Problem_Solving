#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

struct node {
    string head,HEAD,num,tail;
    int idx;
    
    bool operator < (const node& arg) const {
        if(HEAD != arg.HEAD) return HEAD < arg.HEAD;
        else if(stoi(num) != stoi(arg.num)) return stoi(num) < stoi(arg.num);
        return idx < arg.idx;
    }
};
vector<node> v;

vector<string> solution(vector<string> files) {
    vector<string> res;
    
    FOR(i,files.size()) {
        string s = files[i];
        string head = "";
        string HEAD = "";
        string num = "";
        string tail = "";
        bool chk = 0, complete = 0;
        int nIdx = 0;
        FOR(i,s.size()) {
            if(s[i]>='0' && s[i]<='9') {
                if(chk==0) {
                    chk=1;
                    head = s.substr(0,i);
                    nIdx = i;
                }
            }
            else {
                if(chk) {
                    num = s.substr(nIdx,i-nIdx);
                    tail = s.substr(i,s.size()-i);
                    complete = 1;
                    break;
                }
            }
        }
        if(complete == 0) {
            num = s.substr(nIdx,s.size()-nIdx);
        }
        for(auto x: head) {
            if(x>='a' && x<='z') HEAD += x + ('A'-'a');
            else HEAD += x;
        }
        v.push_back({head,HEAD,num,tail,i});
    }
    sort(v.begin(), v.end());
    FOR(i,v.size()) {
        string cur = v[i].head+v[i].num+v[i].tail;
        res.push_back(cur);
    }
    
    return res;
}
