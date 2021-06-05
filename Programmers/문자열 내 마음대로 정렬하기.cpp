#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<char,string> > v;

vector<string> solution(vector<string> strings, int n) {
    vector<string> res;
    for(auto s: strings) {
        v.push_back({s[n],s});
    }
    sort(v.begin(),v.end());
    for(auto x: v) {
        res.push_back(x.second);
    }
    return res;
}
