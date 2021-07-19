#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> res;
    while(n) {
        res.push_back(n%10);
        n/=10;
    }
    return res;
}
