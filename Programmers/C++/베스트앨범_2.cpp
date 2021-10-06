#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

struct node {
    int play,idx;
    bool operator < (const node& arg) const {
        if(play!=arg.play) return play > arg.play;
        return idx < arg.idx;
    }
};

bool comp(pair<string,int> a, pair<string,int> b) {
    return a.second > b.second;
}

vector<int> res;
vector<pair<string,int>> ord;
unordered_map<string,int> num;
unordered_map<string, vector<node>> um;

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    // 1. 장르 합을 구해서 장르 순서를 정함
    FOR(i,genres.size()) {
        string next = genres[i];
        num[next] += plays[i];
        um[next].push_back({plays[i],i});
    }
    for(auto next: num) {
        ord.push_back({next.first, next.second});
    }
    sort(ord.begin(),ord.end(),comp);
    
    // 2. 장르 내에서 정렬하여 2개 수록
    for(auto next: ord) {
        string s = next.first;
        vector<node> v = um[s];
        sort(v.begin(), v.end());
        res.push_back(v[0].idx);
        if(v.size()>1) res.push_back(v[1].idx);
    }

    return res;
}
