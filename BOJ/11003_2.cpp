#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define LINF 9123456789123456789
#define MAX 1005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,l,x,i;
deque<pii> dq;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>l;
    while(n--) {
        cin>>x;
        while(!dq.empty() && dq.front().second <= i-l) dq.pop_front();
        while(!dq.empty() && dq.back().first > x) dq.pop_back();
        dq.push_back({x,i++});
        cout<<dq.front().first<<" ";
    }
}
