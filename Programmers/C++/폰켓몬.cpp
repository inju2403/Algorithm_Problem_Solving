#include <vector>
#include <unordered_map>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef pair<int,int> pii;

int total;
unordered_map<int,int> um;

int solution(vector<int> nums)
{
    total = nums.size()/2;
    for(auto x: nums) ++um[x];
    return min((int)um.size(), total);
}
