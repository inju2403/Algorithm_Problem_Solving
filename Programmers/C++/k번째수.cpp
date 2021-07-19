#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> res;
    FOR(i,commands.size()) {
        vector<int> v;
        FORS(j,commands[i][0]-1,commands[i][1]) v.push_back(array[j]);
        sort(v.begin(),v.end());
        res.push_back(v[commands[i][2]-1]);
    }
    return res;
}
