#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

struct node {
    int w,idx,wCnt;
    double p;
    bool operator < (const node& arg) const {
        if(p!=arg.p) return p>arg.p;
        else if(wCnt!=arg.wCnt) return wCnt>arg.wCnt;
        else if(w!=arg.w) return w>arg.w;
        return idx<arg.idx;
    }
};
vector<node> v;
vector<int> res;

vector<int> solution(vector<int> weights, vector<string> head2head) {
    FOR(i,weights.size()) {
        int w = weights[i];
        int idx = i+1;
        int matchCnt = 0;
        int winCnt = 0;
        int weightWinCnt = 0;
        double p = 0;
        string str = head2head[i];
        FOR(j,str.size()) {
            if(i==j) continue;
            if(str[j]=='N') continue;
            ++matchCnt;
            if(str[j]=='W') {
                ++winCnt;
                if(weights[i]<weights[j]) ++weightWinCnt;
            }
        }
        if(winCnt!=0) p = (double)winCnt / matchCnt;
        v.push_back({w,idx,weightWinCnt,p});
    }
    sort(v.begin(),v.end());
    for(auto x: v) res.push_back(x.idx);
    return res;
}
