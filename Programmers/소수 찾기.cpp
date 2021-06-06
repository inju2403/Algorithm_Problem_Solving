#include <string>
#include <vector>
#define MAX 1000010
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int res,c[MAX];

void getPrime() {
    FORS(i,2,MAX) c[i]=1;
    for(int i=2; i*i<MAX; ++i) {
        if(c[i]==0) continue;
        for(int j=i*i; j<MAX; j+=i) {
            c[j]=0;
        }
    }
}

int solution(int n) {
    getPrime();
    FORS(i,2,n+1) if(c[i]) ++res;
    return res;
}
