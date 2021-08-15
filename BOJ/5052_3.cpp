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
#define MAX 10005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int tc,n;
vector<string> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        bool judge = 1;
        cin>>n;
        v.resize(n);
        FOR(i,n) cin>>v[i];
        sort(v.begin(), v.end());
        FORS(i,1,n) {
            if(v[i].find(v[i-1])==0) {
                judge = 0;
                break;
            }
        }
        cout<<(judge? "YES\n" : "NO\n");
    }
}
