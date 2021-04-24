#include<iostream>
using namespace std;
int n=1,l=1,r,sum,res;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    while(r<=n+1) {
        if(sum>=n) {
            sum-=l;
            ++l;
        }
        else {
            sum+=r;
            ++r;
        }
        if(sum==n) ++res;
    }
    cout<<res;
}
