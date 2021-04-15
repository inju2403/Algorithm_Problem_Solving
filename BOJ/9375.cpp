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
#define MAX 300001
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int tc,n,res=1;
string a,b;
unordered_map<string,int> mp;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        res=1;
        mp.clear();
        cin>>n;
        while(n--) {
            cin>>a>>b;
            ++mp[b];
        }
        for(auto x: mp) res*=(x.second+1);
        cout<<res-1<<'\n';
    }
}
