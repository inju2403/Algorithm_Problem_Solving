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

int n,k,depth,cnt[MAX+1];
queue<int> q;
bool chk,visited[MAX+1];
set<int> st;

void judge(int x,int pre) {
    if(0<=x && x<=MAX && !visited[x]) {
        if(!cnt[x]) {
            q.push(x);
            cnt[x] = cnt[pre];
        }
        else cnt[x] += cnt[pre];
        st.insert(x);
    }
}

int bfs() {
    q.push(n);
    visited[n]=1;
    cnt[n]=1;
    
    while(!q.empty()) {
        int sz = q.size();
        st.clear();
        while(sz--) {
            int cur = q.front();
            q.pop();
            judge(2*cur, cur);
            judge(cur-1, cur);
            judge(cur+1, cur);
            if(cur==k) chk=1;
        }
        if(chk) break;
        ++depth;
        for(auto x: st) visited[x]=1;
    }
    return depth;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    cout<<bfs()<<'\n'<<cnt[k];
}
