#include <iostream>
#include <algorithm>
#include <cstring>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int res;

int solution(int n) {
    while(n) {
        if(n%2==0) n/=2;
        else {
            n-=1;
            res++;
        }
    }
    return res;
}
