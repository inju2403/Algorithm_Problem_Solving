#include<iostream>
using namespace std;

int n,ori,k,tmp,cnt;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n>>k;
    ori=n;
    while(1) {
        cnt=0;
        tmp=n;
        while(tmp) {
            if(tmp%2) ++cnt;
            tmp/=2;
        }
        if(cnt<=k) break;
        ++n;
    }
    cout<<n-ori;
}
