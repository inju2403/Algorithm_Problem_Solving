#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)

using namespace std;

int solution(vector<int> d, int budget) {
    int res = 0;
    sort(d.begin(),d.end());
    FOR(i,d.size()) {
        budget-=d[i];
        if(budget<0) break;
        ++res;
    }
    
    return res;
}
