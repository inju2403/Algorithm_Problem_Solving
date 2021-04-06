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
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int tc,n,x,sum,res=-1000;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>tc;
    while(tc--) {
        res=-1000; sum=0;
        cin>>n;
        FOR(i,n) {
            cin>>x;
            if(sum<0) sum=0;
            sum+=x;
            res=max(sum,res);
        }
        cout<<res<<'\n';
    }
}
