#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

vector<string> res;
unordered_map<string, int> um[11];

void dfs(int idx, int cnt, string& s, string& cur) {
    if(idx>s.size()) return;
    if(cur.size()==cnt) {
        ++um[cnt][cur];
        return;
    }
    cur+=s[idx];
    dfs(idx+1,cnt,s,cur);
    cur.pop_back();
    dfs(idx+1,cnt,s,cur);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    for(string s: orders) {
        sort(s.begin(),s.end());
        FORS(i,2,s.size()+1) {
            string cur = "";
            dfs(0,i,s,cur);
        }
    }
    
    for(int n: course) {
        int mx = 0;
        for(auto x: um[n]) mx=max(mx,x.second);
        if(mx<=1) continue;
        for(auto x: um[n]) if(mx==x.second) res.push_back(x.first);
    }
    
    sort(res.begin(), res.end());
    
    return res;
}
