#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> res;
    for(auto x: arr) {
        if(!(x%divisor)) res.push_back(x);
    }
    sort(res.begin(),res.end());
    if(res.empty()) res.push_back(-1);
    return res;
}
