#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 1010
using namespace std;

int num=1,y=-1,x,a[MAX][MAX];
vector<int> res;

vector<int> solution(int n) {
    
    int ori = n;
    while(n>0) {
        FOR(i,n) a[++y][x] = num++; --n;
        FOR(i,n) a[y][++x] = num++; --n;
        FOR(i,n) a[--y][--x] = num++; --n;
    }
    
    n=ori;
    FOR(y,n) FOR(x,y+1) res.push_back(a[y][x]);
    
    return res;
}
