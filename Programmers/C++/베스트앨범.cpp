#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;
typedef pair<int,int> pii;
typedef pair<string,int> psi;

unordered_map<string,int> u1;
unordered_map<string,vector<pii>> u2;
vector<psi> v;
vector<int> res;

bool comp1(psi a, psi b){
    return a.second > b.second;
}

bool comp2(pii a, pii b) {
    if(a.first!= b.first) return a.first > b.first;
    return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    FOR(i,genres.size()) {
        string s = genres[i];
        int cnt = plays[i];
        u1[s]+=cnt;
        u2[s].push_back({cnt,i});
    }
    
    for(auto x: u1) v.push_back({x.first,x.second});
    sort(v.begin(),v.end(),comp1);
    
    for(auto x: v) {
        string g = x.first;
        sort(u2[g].begin(), u2[g].end(), comp2);
        int cnt = 0;
        for(auto k: u2[g]) {
            res.push_back(k.second);
            if(++cnt==2) break;
        }
    }
    
    return res;
}
