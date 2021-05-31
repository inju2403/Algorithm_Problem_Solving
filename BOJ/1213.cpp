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
#define MAX 30
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int cnt,idx,alpha[26];
string s,res;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>s;
    FOR(i,s.size()) alpha[s[i]-'A']++;
    FOR(i,26) if(alpha[i]%2) ++cnt, idx=i;
    if(cnt>1) {
        cout<<"I'm Sorry Hansoo";
        return 0;
    }
    FOR(i,26) FOR(j,alpha[i]/2) res+='A'+i;
    if(cnt) res+='A'+idx;
    for(int i=25;i>=0;--i) FOR(j,alpha[i]/2) res+='A'+i;
    cout<<res;
}
