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
#define MAX 20010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,x,res=1;
bool chk[MAX];
vector<int> v;

int gcd(int a,int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b) {
    return a*(b/gcd(a,b));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    v.resize(n+1);
    FORS(i,1,n+1) {
        cin>>x;
        v[x]=i;
    }
    FORS(i,1,n+1) {
        if(chk[i]) continue;
        int j=i;
        int cnt=0;
        while(1) {
            if(chk[j]) break;
            chk[j]=1;
            ++cnt;
            
            j=v[j];
        }
        res=lcm(res,cnt);
    }
    cout<<res;
}
