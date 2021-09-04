#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

vector<int> res;
unordered_map<string, vector<int>> um;

void dfs(int idx, int cnt, vector<string>& v, vector<int>& k) {
    if(k.size()==cnt) {
        string str = "";
        bool chk[4]={0,};
        for(auto x: k) chk[x]=1;
        FOR(i,4) {
            if(chk[i]) str+=v[i];
            else str+="-";
        }
        int score = stoi(v[4]);
        um[str].push_back(score);
        return;
    }
    if(idx==v.size()-1) return;
    k.push_back(idx);
    dfs(idx+1,cnt,v,k);
    k.pop_back();
    dfs(idx+1,cnt,v,k);
}

vector<int> solution(vector<string> info, vector<string> query) {
    
    for(auto s: info) {
        vector<string> v;
        string cur = "";
        
        for(auto c: s) {
            if(c==' ') {
                v.push_back(cur);
                cur="";
            }
            else cur+=c;
        }
        v.push_back(cur);
        
        int score = stoi(v[4]);
        
        FOR(cnt,5) {
            vector<int> k;
            dfs(0,cnt,v,k);
        }
    }
    
    for(auto s: query) {
        vector<string> v;
        string cur = "";
        
        for(auto c: s) {
            if(c==' ') {
                if(cur!="and") v.push_back(cur);
                cur="";
            }
            else cur+=c;
        }
        v.push_back(cur);
        
        string str = v[0]+v[1]+v[2]+v[3];
        int sum = 0;
        int score = stoi(v[4]);
        for(auto x: um[str]) {
            if(x>=score) ++sum;
        }
        res.push_back(sum);
    }
    
    return res;
}
