#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,w[22],v[22],d[101];

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    FORS(i,1,n+1) cin>>w[i];
    FORS(i,1,n+1) cin>>v[i];
    FORS(i,1,n+1) {
        for(int j=100+1;j>=w[i]+1;--j) {
            d[j]=max(d[j-w[i]]+v[i], d[j]);
        }
    }
    cout<<d[100];
}
