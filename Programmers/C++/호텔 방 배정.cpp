#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map<ll,ll> f;

ll find(ll x) {
    if(!f[x]) {
        f[x]=x+1;
        return x;
    }
    return f[x] = find(f[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<ll> res;
    for(auto x: room_number) {
        res.push_back(find(x));
    }
    return res;
}
