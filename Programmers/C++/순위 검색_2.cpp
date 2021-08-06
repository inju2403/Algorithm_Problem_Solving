#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;
vector<int> idxs,res;
vector<string> v;
unordered_map<string,vector<int>> um;

void dfs(int sz, int idx, int score) {
    if(idxs.size()==sz) {
        bool chk[4] = {0,0,0,0};
        for(int k: idxs) chk[k]=1;
        string s = "";
        FOR(i,4) {
            if(chk[i]) s+='-';
            else s+=v[i];
        }
        um[s].push_back(score);
        return;
    }
    FORS(i,idx,4) {
        idxs.push_back(i);
        dfs(sz,i+1,score);
        idxs.pop_back();
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    for(string s: info) {
        v.clear();
        idxs.clear();
        string tmp = "";
        FOR(i,s.size()+1) {
            if(i==s.size() || s[i]==' ') {
                v.push_back(tmp);
                tmp="";
            } else tmp+=s[i];
        }
        FOR(sz,5) dfs(sz,0,stoi(v[4]));
    }
    
    for(string s: query) {
        v.clear();
        string tmp = "";
        FOR(i,s.size()+1) {
            if(i==s.size() || s[i]==' ') {
                v.push_back(tmp);
                tmp="";
            } else tmp+=s[i];
        }
        string cur = "";
        FOR(i,v.size()-1) {
            string x = v[i];
            if(x=="and") continue;
            cur+=x;
        }
        int score = stoi(v[v.size()-1]);
        int cnt = 0;
        for(int k: um[cur]) if(k>=score) ++cnt;
        res.push_back(cnt);
    }
    return res;
}
