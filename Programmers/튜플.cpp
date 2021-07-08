#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
using namespace std;

vector<vector<int>> v;
vector<int> k;
string cur;
unordered_map<int,bool> um;

bool comp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> res;
    FOR(i,s.size()-1) {
        if(s[i]=='{') continue;
        else if(s[i]=='}') {
            k.push_back(stoi(cur));
            um[stoi(cur)]=1;
            v.push_back(k);
            k.clear();
            cur="";
        }
        else if(s[i]==',') {
            if(cur=="") continue;
            k.push_back(stoi(cur));
            um[stoi(cur)]=1;
            cur="";
        }
        else cur+=s[i];
    }
    sort(v.begin(), v.end(), comp);
    FOR(i,v.size()) {
        for(auto x: v[i]) {
            if(um[x]) {
                um[x]=0;
                res.push_back(x);
            }
        }
    }
    return res;
}
