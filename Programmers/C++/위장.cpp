#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int res=1;
unordered_map<string,int> um;

int solution(vector<vector<string>> clothes) {
    for(auto x: clothes) um[x[1]]++;
    for(auto x: um) res*=(x.second+1);
    return res-1;
}
