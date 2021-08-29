#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int res;

void judge(string k) {
    stack<char> st;
    
    bool chk = 1;
    for(auto c: k) {
        if(c=='(' || c=='[' || c=='{') st.push(c);
        else {
            if(st.empty()
               || (c==']'&&st.top()!='[')
               || (c=='}'&&st.top()!='{')
               || (c==')'&&st.top()!='(')) {
                chk=0;
                break;
            }
            st.pop();
        }
    }
    if(st.size()) chk=0;
    if(chk) ++res;
}

int solution(string s) {
    
    FOR(i,s.size()) {
        string k = s.substr(i,s.size()-i);
        FOR(j,i) k+=s[j];
        judge(k);
    }
    
    return res;
}
