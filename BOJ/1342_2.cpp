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

int res;
bool chk=1;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>s;
    sort(s.begin(),s.end());
    do {
        chk=1;
        FOR(i,s.size()-1) if(s[i]==s[i+1]) {
            chk=0;
            break;
        }
        if(chk) ++res;
    } while(next_permutation(s.begin(), s.end()));
    cout<<res;
}
