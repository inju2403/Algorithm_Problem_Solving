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
#define MAX 11
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int res,dv=1;
string s;
vector<char> v;
bool visited[MAX];
unordered_map<char, int> mp;

int factorial(int x) {
    int ret=1;
    for(int i=x; i>1; --i) ret*=i;
    return ret;
}

void dfs(int idx, vector<char>& v) {
    if(v.size()==s.size()) {
        bool chk = 1;
        FOR(i,v.size()-1) if(v[i]==v[i+1]) {
            chk=0;
            break;
        }
        if(chk) ++res;
        return;
    }
    FOR(i,s.size()) {
        if(visited[i]) continue;
        visited[i]=1; v.push_back(s[i]);
        dfs(i,v);
        visited[i]=0; v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>s;
    FOR(i,s.size()) ++mp[s[i]];
    for(auto x: mp) dv *= factorial(x.second);
    dfs(0,v);
    cout<<res/dv;
}
