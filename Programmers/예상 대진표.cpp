#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    if(a>b) swap(a,b);
    int cnt=1;
    while(1) {
        a%2==0? a/=2 : a=(a+1)/2;
        b%2==0? b/=2 : b=(b+1)/2;
        ++cnt;
        
        if(a==b) {
            --cnt;
            break;
        }
        if(b-a==1 && b%2==0) break;
    }
    return cnt;
}
