#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 51
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,res;
string s[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    FOR(i,n) cin>>s[i];
    FOR(i,n) {
        int sum=0;
        FOR(j,n) {
            if(i==j) continue;
            if(s[i][j]=='Y') ++sum;
            else {
                FOR(k,n) {
                    if(s[i][k]=='Y' && s[k][j]=='Y') {
                        ++sum;
                        break;
                    }
                }
            }
        }
        res=max(res,sum);
    }
    cout<<res;
}
