#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 205

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

ll mn=INF, dist[MAX][MAX];

void floyd(int n) {
    FORS(k,1,n+1) FORS(i,1,n+1) FORS(j,1,n+1) {
        if(dist[i][j] > dist[i][k]+dist[k][j]) {
            dist[i][j] = dist[i][k]+dist[k][j];
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    FORS(i,1,n+1) FORS(j,1,n+1) if(i!=j) dist[i][j]=INF;
    for(auto x: fares) {
        dist[x[0]][x[1]]=x[2];
        dist[x[1]][x[0]]=x[2];
    }
    
    floyd(n);
    
    FORS(i,1,n+1) mn = min(mn, dist[s][i]+dist[a][i]+dist[b][i]);
    
    return mn;
}
