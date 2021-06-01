#include <iostream>
#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)

using namespace std;

int zero,sum;
bool chk[50];

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> res;
    for(auto x: lottos) {
        if(x) chk[x]=1;
        else zero++;
    }
    for(auto x: win_nums) if(chk[x]) ++sum;
    res.push_back(max(1,min(6,7-(sum+zero))));
    res.push_back(min(6,7-sum));
    return res;
}
