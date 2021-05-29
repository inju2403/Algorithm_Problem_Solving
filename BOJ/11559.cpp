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
#define MAX 12
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

int res;
string mp[12];
bool chk,visited[12][6],judge[12][6];
unordered_map<char, int> um;

struct node {
    int y,x;
    char ch;
};

bool isRange(int y,int x) {
    return y>=0 && y<12 && x>=0 && x<6;
}

void bfs(int y,int x) {
    vector<pii> v;
    queue<node> q;
    q.push({y,x,mp[y][x]});
    um[mp[y][x]]=1;
    
    while(!q.empty()) {
        int cy = q.front().y;
        int cx = q.front().x;
        char ch = q.front().ch;
        v.push_back({cy,cx});
        q.pop();
        
        FOR(dir,4) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(!isRange(ny,nx) || visited[ny][nx] || mp[ny][nx]!=ch) continue;
            visited[ny][nx]=1;
            q.push({ny,nx,ch});
            v.push_back({ny,nx});
            um[ch]++;
        }
    }
    
    if(um[mp[y][x]]>=4) {
        FOR(i,v.size()) {
            int cy = v[i].first;
            int cx = v[i].second;
            judge[cy][cx]=1;
        }
        chk=0;
    }
    um[mp[y][x]]=0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    FOR(i,12) cin>>mp[i];
    while(1) {
        chk=1;
        memset(visited,0,sizeof(visited));
        memset(judge,0,sizeof(judge));
        
        //1. 터뜨릴 애들 체크하기 -> judge 배열에 체크
        FOR(y,12) FOR(x,6) {
            if(mp[y][x]!='.') {
                if(visited[y][x]) continue;
                visited[y][x]=1;
                bfs(y,x);
            }
        }
        if(chk) break;
        
        //2. 떨구기 -> 각 열마다 judge 배열에 체크된 애들을 터뜨리고 위에 있는 뿌요들을 떨어뜨린다.
        FOR(x,6) {
            int cnt=0;
            FOR(y,12) {
                if(!judge[y][x] && !cnt) continue;
                if(judge[y][x]) {
                    ++cnt;
                    if(y!=11) continue;
                }
                //cnt 만큼 아래로 내리기
                if(y==11 && judge[y][x]) for(int Y=11; Y>=cnt; --Y) mp[Y][x] = mp[Y-cnt][x];
                else {
                    for(int Y=y-1; Y>=cnt; --Y) mp[Y][x] = mp[Y-cnt][x];
                    FOR(Y,cnt) mp[Y][x] = '.';
                }
                
                cnt=0;
            }
        }
        ++res;
    }
    cout<<res;
}
