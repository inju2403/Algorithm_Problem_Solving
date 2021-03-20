#include<iostream>
#include<algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int x,y,num=1,i=1,sum,a[1050];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>x>>y;
    while(i<y+1) {
        FOR(j,num) a[i++]=num;
        num++;
    }
    FORS(j,x,y+1) sum+=a[j];
    cout<<sum;
}
