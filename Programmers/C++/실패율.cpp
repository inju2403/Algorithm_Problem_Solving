#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 505
using namespace std;

int mp[MAX],sum[MAX];

struct node {
    int idx;
    double score;
    
    bool operator < (const node& arg) const {
        if(score!=arg.score) return score>arg.score;
        return idx<arg.idx;
    }
};
vector<node> v;

vector<int> solution(int N, vector<int> stages) {
    vector<int> res;
    
    int total = stages.size();
    
    for(auto x: stages) mp[x]++;
    FORS(i,1,N+1) sum[i] = sum[i-1] + mp[i];
    
    FORS(i,1,N+1) {
        int dv = total-sum[i-1];
        double f;
        dv==0? f=0 : f=(double)mp[i]/dv;
        v.push_back({i,f});
    }
    sort(v.begin(),v.end());
    for(auto x: v) res.push_back(x.idx);
    return res;
}
