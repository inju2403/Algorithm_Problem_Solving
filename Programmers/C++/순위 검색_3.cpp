#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

vector<int> res;
unordered_map<string, vector<int>> um;

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
        
        um[v[0]+v[1]+v[2]+v[3]].push_back(score);
        
        um["-"+v[1]+v[2]+v[3]].push_back(score);
        um[v[0]+"-"+v[2]+v[3]].push_back(score);
        um[v[0]+v[1]+"-"+v[3]].push_back(score);
        um[v[0]+v[1]+v[2]+"-"].push_back(score);
        
        um["--"+v[2]+v[3]].push_back(score);
        um["-"+v[1]+"-"+v[3]].push_back(score);
        um["-"+v[1]+v[2]+"-"].push_back(score);
        um[v[0]+"--"+v[3]].push_back(score);
        um[v[0]+"-"+v[2]+"-"].push_back(score);
        um[v[0]+v[1]+"--"].push_back(score);
        
        um["---"+v[3]].push_back(score);
        um["--"+v[2]+"-"].push_back(score);
        um["-"+v[1]+"--"].push_back(score);
        um[v[0]+"---"].push_back(score);
        
        um["----"].push_back(score);
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
