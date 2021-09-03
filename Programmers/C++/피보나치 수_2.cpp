#include <string>
#include <vector>
#include <cstring>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 100001
#define MOD 1234567
using namespace std;

int cache[MAX];

int f(int x) {
    if(x==0) return 0;
    if(x==1) return 1;
    
    int& ret = cache[x];
    if(ret!=-1) return ret;
    return ret = (f(x-1)+f(x-2))%MOD;
}

int solution(int n) {
    memset(cache,-1,sizeof(cache));
    return f(n);
}
