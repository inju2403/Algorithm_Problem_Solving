#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;
vector<int> res;
unordered_map<string,vector<int>> um;

vector<int> solution(vector<string> info, vector<string> query) {
    for(string s: info) {
        vector<string> v;
        string tmp = "";
        FOR(i,s.size()+1) {
            if(i==s.size() || s[i]==' ') {
                v.push_back(tmp);
                tmp="";
            } else tmp+=s[i];
        }
        um["----"].push_back(stoi(v[4]));
        
        um["-"+v[1]+v[2]+v[3]].push_back(stoi(v[4]));
        um[v[0]+"-"+v[2]+v[3]].push_back(stoi(v[4]));
        um[v[0]+v[1]+"-"+v[3]].push_back(stoi(v[4]));
        um[v[0]+v[1]+v[2]+"-"].push_back(stoi(v[4]));
        
        um["--"+v[2]+v[3]].push_back(stoi(v[4]));
        um["-"+v[1]+"-"+v[3]].push_back(stoi(v[4]));
        um["-"+v[1]+v[2]+"-"].push_back(stoi(v[4]));
        um[v[0]+"--"+v[3]].push_back(stoi(v[4]));
        um[v[0]+"-"+v[2]+"-"].push_back(stoi(v[4]));
        um[v[0]+v[1]+"--"].push_back(stoi(v[4]));
        
        um["---"+v[3]].push_back(stoi(v[4]));
        um["--"+v[2]+"-"].push_back(stoi(v[4]));
        um["-"+v[1]+"--"].push_back(stoi(v[4]));
        um[v[0]+"---"].push_back(stoi(v[4]));
        
        um[v[0]+v[1]+v[2]+v[3]].push_back(stoi(v[4]));
    }
    
    for(string s: query) {
        vector<string> v;
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
