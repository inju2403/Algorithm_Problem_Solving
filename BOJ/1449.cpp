#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,l,x,cnt,i,a[1005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>l;
    FOR(i,n) {
        cin>>x;
        a[x]=1;
    }
    while(i<1001) {
        if(a[i]) {
            i+=l;
            ++cnt;
        }
        else ++i;
    }
    cout<<cnt;
}
