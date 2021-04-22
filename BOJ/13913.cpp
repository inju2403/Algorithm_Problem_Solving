#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
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

int n,k,depth,route[MAX+1];
queue<int> q;
bool chk,visited[MAX+1];
vector<int> path;

void judge(int x,int pre) {
    if(0<=x && x<=MAX && !visited[x]) {
        route[x]=pre;
        q.push(x);
        visited[x]=1;
    }
}

int bfs() {
    q.push(n);
    visited[n]=1;
    
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int cur = q.front();
            q.pop();
            if(cur==k) {
                chk=1;
                break;
            }
            judge(2*cur, cur);
            judge(cur-1, cur);
            judge(cur+1, cur);
        }
        if(chk) break;
        ++depth;
    }
    return depth;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    cout<<bfs()<<'\n';
    int cur = k;
    while(cur!=n) {
        path.push_back(cur);
        cur=route[cur];
    }
    path.push_back(n);
    for(int i=path.size()-1; i>=0; --i) cout<<path[i]<<" ";
}
