#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    
    vector<vector<int>> res;
    
    res.resize(arr1.size());
    FOR(i,res.size()) res[i].resize(arr2[0].size());
    
    FOR(y,res.size()) FOR(x,res[0].size()) {
        FOR(i,arr1[0].size()) {
            res[y][x]+= arr1[y][i]*arr2[i][x];
        }
    }
    
    return res;
}
