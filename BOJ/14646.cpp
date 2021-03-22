#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,x,cnt,mx,a[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    FOR(i,2*n) {
        cin>>x;
        if(a[x-1]==0) {
            a[x-1]=1;
            ++cnt;
            mx=max(mx,cnt);
        }
        else {
            a[x-1]=0;
            --cnt;
        }
    }
    cout<<mx;
}
