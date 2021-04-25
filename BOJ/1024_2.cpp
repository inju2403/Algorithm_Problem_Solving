#include<iostream>
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,l,k,x;

int main() {
    cin>>n>>l;
    FORS(i,l,101) {
        k=(i-1)*i/2;
        if((n-k)%i==0 && (n-k)/i>=0) {
            x=(n-k)/i;
            FORS(j,x,x+i) cout<<j<<" ";
            return 0;
        }
    }
    cout<<-1;
}
