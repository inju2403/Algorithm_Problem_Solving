#include <vector>
#include <iostream>
#include <algorithm>
#define FOR(i,n) for(int i=0; i<(n); ++i)
#define FORS(i,s,n) for(int i=(s); i<(n); ++i)
#define MAX 3005
using namespace std;

int res,s[MAX];

void sieve() {
    FOR(i,MAX) s[i]=1;
    for (int i = 2; i*i <= 3001; ++i) {
        if (s[i] == 0) continue;
        for (int j = i * i; j <= 3001; j += i) {
            if (s[j] == 0) continue;
            s[j] = 0;
        }
    }
}

int solution(vector<int> nums) {
    int res = 0;
    sieve();
    FOR(i,nums.size()) {
        FORS(j,i+1,nums.size()) {
            FORS(k,j+1,nums.size()) {
                int n = nums[i]+nums[j]+nums[k];
                if(s[n]) ++res;
            }
        }
    }

    return res;
}
