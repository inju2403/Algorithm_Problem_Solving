#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 1987654321
using namespace std;

int cur;

int solution(vector<int> A, vector<int> B) {
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    
    FOR(i,A.size()) cur+=A[i]*B[i];

    return cur;
}
