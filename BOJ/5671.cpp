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
#define MAX 105
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int a,b;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>>a>>b) {
        int res = 0;
        FORS(i,a,b+1) {
            bool chk[10] = {0,};
            bool judge = 1;
            string s = to_string(i);
            for(auto c: s) {
                int num = c-'0';
                if(chk[num]) {
                    judge = 0;
                    break;
                }
                chk[num]=1;
            }
            if(judge) ++res;
        }
        cout<<res<<'\n';
    }
}
