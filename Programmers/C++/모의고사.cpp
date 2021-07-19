#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

const int a[5]={1,2,3,4,5};
const int b[8]={2,1,2,3,2,4,2,5};
const int c[10]={3,3,1,1,2,2,4,4,5,5};
int r1,r2,r3;

vector<int> solution(vector<int> input) {
    vector<int> res;
    
    FOR(i,input.size()) if(input[i]==a[i%5]) ++r1;
    FOR(i,input.size()) if(input[i]==b[i%8]) ++r2;
    FOR(i,input.size()) if(input[i]==c[i%10]) ++r3;
    
    int mx = max({r1,r2,r3});
    if(r1==mx) res.push_back(1);
    if(r2==mx) res.push_back(2);
    if(r3==mx) res.push_back(3);
    sort(res.begin(),res.end());
    
    return res;
}
