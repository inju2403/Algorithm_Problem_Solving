#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 101

using namespace std;
int mn = INF;
vector<int> adj[MAX];
bool visited[MAX];

int dfs(int x, int a, int b) {
    int ret = 1;
    for(auto next: adj[x]) {
        if((x==a&&next==b) || (x==b&&next==a)) continue;
        if(visited[next]) continue;
        visited[next] = 1;
        ret += dfs(next,a,b);
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    for(auto x: wires) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    for(auto x: wires) {
        memset(visited,0,sizeof(visited));
        int a[2] = {0,0};
        int idx = 0;
        FORS(i,1,n+1) {
            if(visited[i]) continue;
            visited[i] = 1;
            a[idx++] = dfs(i,x[0],x[1]);
        }
        mn = min(mn, abs(a[0]-a[1]));
    }
    return mn;
}
