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
#define MAX 21
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,idx;
string p,s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>p;
    FOR(i,p.size()) if(p[i]=='*') {
        idx = i;
        break;
    }
    while(n--) {
        cin>>s;
        if(s.size()<p.size()-1) {
            cout<<"NE\n";
            continue;
        }
        bool judge = 1;
        FOR(i,idx) {
            if(p[i]!=s[i]) {
                judge = 0;
                break;
            }
        }
        if(idx!=p.size()-1) {
            FOR(i,p.size()-idx) {
                if(p[p.size()-i] != s[s.size()-i]) {
                    judge = 0;
                    break;
                }
            }
        }
        cout<<(judge? "DA" : "NE")<<'\n';
    }
}
