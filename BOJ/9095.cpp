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
#define MAX 1005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int tc,x,d[11];
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    d[1]=1;
    d[2]=2;
    d[3]=4;
    FORS(i,4,11) d[i]=d[i-1]+d[i-2]+d[i-3];
    while(tc--) {
        cin>>x;
        cout<<d[x]<<'\n';
    }
}
