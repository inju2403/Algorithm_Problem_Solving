#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

string h,m,s,ms,process;
int iH,iM,iS,iMs,iProcess,res;
vector<int> st,ed;

int solution(vector<string> lines) {
    
    for(auto x: lines) {
        x.pop_back();
        h = x.substr(11,2);
        m = x.substr(14,2);
        s = x.substr(17,2);
        ms = x.substr(20,3);
        process = x.substr(24,5);
        
        iH = stoi(h)*3600*1000;
        iM = stoi(m)*60*1000;
        iS = stoi(s)*1000;
        iMs = stoi(ms);
        iProcess = stod(process)*1000;
        
        st.push_back(iH+iM+iS+iMs -iProcess+1);
        ed.push_back(iH+iM+iS+iMs);
    }
    
    FOR(i,st.size()) {
        int cnt=1;
        FORS(j,i+1,st.size()) {
            int end = ed[i] + 999; // 1초 동안
            if(st[j] <= end) ++cnt;
        }
        res=max(res,cnt);
    }
    
    return res;
}
