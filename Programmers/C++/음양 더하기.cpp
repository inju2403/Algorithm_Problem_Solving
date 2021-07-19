#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int res = 0;
    FOR(i,absolutes.size()) {
        if(signs[i]==false) res-=absolutes[i];
        else res+=absolutes[i];
    }
    return res;
}
