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
#define MAX 100005
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,cnt,res;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>s;
    for(char c: s) if(c!='C') ++cnt;
    res = (n-cnt)/(cnt+1);
    if((n-cnt)%(cnt+1)) ++res;
    cout<<res;
}
