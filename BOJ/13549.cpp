#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 100000
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,k,depth;
queue<pii> q;
bool visited[MAX+1];

void judge(int x,int cnt) {
    if(x>=0 && x<=MAX && !visited[x]) {
        visited[x]=1;
        q.push({x,cnt});
    }
}

int bfs() {
    q.push({n,0});
    visited[n]=1;
    
    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur==k) {
            depth = cnt;
            break;
        }
        
        judge(2*cur,cnt);
        judge(cur-1,cnt+1);
        judge(cur+1,cnt+1);
    }
    return depth;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    cout<<bfs();
}
