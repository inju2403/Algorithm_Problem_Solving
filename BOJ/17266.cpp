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
#define MAX 10010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,m,x,pre,mx;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    cin>>x;
    mx=max(mx,x-pre);
    pre=x;
    while(--m) {
        cin>>x;
        mx=max(mx,(x-pre+1)/2);
        pre=x;
    }
    mx=max(mx,n-pre);
    cout<<mx;
}
