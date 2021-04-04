#include<iostream>
#define FOR(i,n) for(int i=0;i<(n);++i)
using namespace std;

int n,a[2][1001],a1;

int main() {
    cin>>n;
    FOR(y,2) FOR(x,n) cin>>a[y][x];
    a1=(a[0][1]+a[0][2]-a[1][2])/2;
    cout<<a1<<" ";
    FOR(i,n-1) cout<<a[0][i+1]-a1<<" ";
}
