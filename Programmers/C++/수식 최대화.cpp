#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;
typedef long long ll;

ll res;
vector<string> ori,tmp,cur,od;
string s;
unordered_map<string, bool> um;

long long solution(string exp) {
    //1. 파싱
    FOR(i,exp.size()) {
        string x = "";
        x+=exp[i];
        if(x<"0" || x>"9" || i==exp.size()-1) {
            if(i<exp.size()-1) {
                ori.push_back(s);
                ori.push_back(x); // x: 연산자
                if(!um[x]) {
                    um[x]=1;
                    od.push_back(x);
                }
            }
            else ori.push_back(s+=x);
            s="";
        }
        else s+=x;
    }
    
    // 2. 연산
    sort(od.begin(), od.end());
    
    do {
        tmp.clear();
        for(auto x: ori) tmp.push_back(x);
        for(auto o: od) {
            cur.clear();
            cur.push_back(tmp[0]);
            FORS(i,1,tmp.size()) {
                if(tmp[i]==o) {
                    ll pre = stoll(cur.back()); cur.pop_back();
                    ll next = stoll(tmp[i+1]);
                    ll sum=0;
                    if(o=="+") sum = pre + next;
                    else if(o=="-") sum = pre - next;
                    else if(o=="*") sum = pre * next;
                    cur.push_back(to_string(sum));
                    ++i;
                }
                else cur.push_back(tmp[i]);
            }
            tmp.clear();
            for(auto x: cur) tmp.push_back(x);
        }
        res=max(res, abs(stoll(tmp[0])));
    } while(next_permutation(od.begin(), od.end()));
    
    return res;
}
