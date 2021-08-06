#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int mx;
vector<string> res;
unordered_map<string, int> um;

void dfs(int cnt, int idx, string ori, string s) {
    if(cnt == s.size()) {
        um[s]++;
        return;
    }
    FORS(i,idx,ori.size()) {
        s+=ori[i];
        dfs(cnt,i+1,ori,s);
        s.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for(int cnt: course) {
        mx=0;
        um.clear();
        string tmp = "";
        for(string s: orders) {
            sort(s.begin(),s.end());
            tmp = "";
            dfs(cnt,0,s,tmp);
        }
        for(auto k: um) mx=max(mx,k.second);
        for(auto k: um) {
            if(k.second==mx && mx>=2) res.push_back(k.first);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
