#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
long long i=1;

long long solution(long long n) {
    long long res = 0;
    while(n) {
        v.push_back(n%10);
        n/=10;
    }
    sort(v.begin(),v.end());
    for(auto x: v) {
        res+=x*i;
        i*=10;
    }
    return res;
}
