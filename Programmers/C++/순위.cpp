#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 105

using namespace std;

int n,res,dist[MAX][MAX];

void floyd() {
    FORS(k,1,n+1) FORS(i,1,n+1) FORS(j,1,n+1) {
        if(dist[i][j] > dist[i][k]+dist[k][j]) {
            dist[i][j] = dist[i][k]+dist[k][j];
        }
    }
    
    FORS(i,1,n+1) {
        int c1 = 0, c2 = 0;
        FORS(j,1,n+1) {
            if(i==j) continue;
            if(dist[i][j]!=INF) ++c1;
            if(dist[j][i]!=INF) ++c2;
        }
        if(c1+c2 == n-1) ++res;
    }
}

int solution(int N, vector<vector<int>> results) {
    n = N;
    FORS(i,1,n+1) FORS(j,1,n+1) if(i!=j) dist[i][j]=INF;
    for(auto x: results) {
        dist[x[0]][x[1]]=1;
    }
    floyd();
    
    return res;
}
