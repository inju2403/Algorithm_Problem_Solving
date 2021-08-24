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
#define LINF 2123456789123456789
#define MAX 21
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n;
string a,b;
unordered_map<string,bool> um;
vector<string> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    while(n--) {
        cin>>a>>b;
        if(b=="enter") um[a]=1;
        else um.erase(a);
    }
    for(auto x: um) v.push_back(x.first);
    sort(v.begin(),v.end(),greater<string>());
    for(auto x: v) cout<<x<<'\n';
}
