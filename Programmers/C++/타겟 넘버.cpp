#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int res;

void dfs(vector<int>& n, int target, int sum, int idx) {
    if(idx==n.size()) {
        if(sum==target) ++res;
        return;
    }
    dfs(n,target,sum+n[idx],idx+1);
    dfs(n,target,sum-n[idx],idx+1);
}

int solution(vector<int> n, int target) {
    dfs(n,target,0,0);
    
    return res;
}
