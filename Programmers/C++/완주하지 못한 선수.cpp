#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)

using namespace std;
unordered_map<string, int> um;

string solution(vector<string> p, vector<string> c) {
    FOR(i,p.size()) ++um[p[i]];
    FOR(i,c.size()) --um[c[i]];
    FOR(i,p.size()) if(um[p[i]]) return p[i];
}
