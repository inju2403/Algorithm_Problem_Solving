#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 100001
#define MOD 1234567
using namespace std;

int a[MAX]={0,1,};

int solution(int n) {
    FORS(i,2,n+1) a[i]=(a[i-1]+a[i-2])%MOD;
    return a[n];
}
