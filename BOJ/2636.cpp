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
#define MAX 101
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

int n,m,t,remain,sum,mp[MAX][MAX];
bool visited[MAX][MAX];
queue<pii> air,melt;

bool isRange(int y,int x) {
    return y>=0 && y<n && x>=0 && x<m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    //1. 외부 공기를 큐에 넣고 + 외부 공기랑 맞닿은 치즈들을 치즈 큐에 넣음
    //2. 총 치즈량에서 치즈큐에 있는 수량을 빼고 + 외부공기큐를 비우고 치즈큐에 있는 애들을 넣음 + 치즈큐에 있는애들 0으로 세팅
    
    cin>>n>>m;
    FOR(y,n) FOR(x,m) {
        cin>>mp[y][x];
        if(mp[y][x]==1) ++remain;
    }
    
    air.push({0,0});
    visited[0][0]=1;
    while(1) {
        ++t;
        while(!air.empty()) {
            int cy = air.front().first;
            int cx = air.front().second;
            air.pop();
            
            FOR(dir,4) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(!isRange(ny,nx) || visited[ny][nx]) continue;
                visited[ny][nx]=1;
                
                if(mp[ny][nx]==0) air.push({ny,nx});
                else {
                    melt.push({ny,nx});
                    mp[ny][nx]=0;
                    ++sum;
                }
            }
        }
        
        remain-=sum;
        if(remain==0) {
            cout<<t<<'\n'<<sum;
            break;
        }
        swap(air,melt);
        queue<pii> emptyQ;
        swap(melt,emptyQ);
        sum=0;
    }
}
