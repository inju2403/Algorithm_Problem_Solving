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

int tc,n,d[MAX];

int gcd(int a,int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    d[1]=2;
    FORS(i,2,1001) {
        int sum = 0;
        FORS(j,1,i) if(gcd(i,j)==1) ++sum;
        d[i] = d[i-1] + sum;
    }
    cin>>tc;
    while(tc--) {
        cin>>n;
        cout<<d[n]*2-1<<'\n';
    }
}
