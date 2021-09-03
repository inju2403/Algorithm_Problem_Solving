#include <iostream>
#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int res;

int solution(int n) {
    
    FORS(i,1,n+1) {
        int sum =0;
        FORS(j,i,n+1) {
            sum+=j;
            if(sum==n) {
                ++res;
                break;
            }
            if(sum>n) break;
        }
    }
    return res;
}
