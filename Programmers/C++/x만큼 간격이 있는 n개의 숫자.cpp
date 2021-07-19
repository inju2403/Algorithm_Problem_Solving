#include <string>
#include <vector>

using namespace std;
vector<long long> v;

vector<long long> solution(int x, int n) {
    for(long long i=x,cnt=0;cnt<n;i+=x,++cnt) v.push_back(i);
    return v;
}
