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

int tc;
string s,tmp;
vector<string> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    cin.ignore();
    while(tc--) {
        v.clear();
        getline(cin,s);
        tmp = "";
        for(char c: s) {
            if(c==' ') {
                v.push_back(tmp);
                tmp = "";
            }
            else tmp += c;
        }
        v.push_back(tmp);
        for(string k: v) {
            reverse(k.begin(), k.end());
            cout<<k<<" ";
        }
        cout<<'\n';
    }
}
