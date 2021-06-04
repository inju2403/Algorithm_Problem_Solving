#include <string>
#include <vector>
#include <set>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

set<int> st;

vector<int> solution(vector<int> numbers) {
    vector<int> v;
    FOR(i,numbers.size()) {
        FORS(j,i+1,numbers.size()) {
            st.insert(numbers[i]+numbers[j]);
        }
    }
    for(auto x: st) v.push_back(x);
    sort(v.begin(),v.end());
    return v;
}
