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

string s,t,res;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    getline(cin,s);
    string tmp = "";
    for(auto c: s) {
        if(c==' ') {
            t = tmp;
            tmp = "";
        }
        else tmp += c;
    }
    reverse(t.begin(),t.end());
    reverse(tmp.begin(),tmp.end());
    int num = stoi(t) + stoi(tmp);
    res = to_string(num);
    reverse(res.begin(),res.end());
    cout<<stoi(res);
}

