#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 55
using namespace std;
typedef pair<int,int> pii;

int res,dist[MAX][MAX];

int solution(int n, vector<vector<int> > road, int k) {
    FORS(i,1,n+1) FORS(j,1,n+1) if(i!=j) dist[i][j]=INF;
    for(auto x: road) {
        dist[x[0]][x[1]] = min(dist[x[0]][x[1]], x[2]);
        dist[x[1]][x[0]] = min(dist[x[1]][x[0]], x[2]);
    }
    FORS(k,1,n+1) {
        FORS(i,1,n+1) FORS(j,1,n+1) {
            if(dist[i][j] > dist[i][k]+dist[k][j]) {
                dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    FORS(i,1,n+1) if(dist[1][i]<=k) ++res;
    return res;
}
