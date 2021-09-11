#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
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
#define MAX 1010
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int num;
string a,b,res;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>a>>b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.size()<b.size()) swap(a,b);
    FOR(i,b.size()) {
        int k = (a[i] - '0') + (b[i] - '0') + num;
        if(k>=2) num = 1;
        else num = 0;
        res += to_string(k%2);
    }
    FORS(i,b.size(),a.size()) {
        int k = (a[i] - '0') + num;
        if(k>=2) num = 1;
        else num = 0;
        res += to_string(k%2);
    }
    if(num) res += "1";
    reverse(res.begin(), res.end());
    while(res[0]=='0') res = res.substr(1);
    if(res.empty()) res="0";
    cout<<res;
}
