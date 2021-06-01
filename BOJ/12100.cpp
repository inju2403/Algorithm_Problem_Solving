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
#define MAX 25
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,res,ori[MAX][MAX],mp[MAX][MAX];

void dfs(int dir, int cnt) {
    if(cnt==5) {
        FOR(y,n) FOR(x,n) res=max(res,mp[y][x]);
        return;
    }
    bool chk[MAX][MAX]={0,};
    int tmp[MAX][MAX];
    switch(dir) {
        case 0://왼
            FOR(y,n) FORS(x,1,n) {
                if(mp[y][x]==0) continue;
                for(int nx=x-1;nx>=0;--nx) {
                    if(mp[y][nx]==0) {
                        if(nx>0) continue;
                        mp[y][nx]=mp[y][x];
                        mp[y][x]=0;
                    }
                    else {
                        if(mp[y][nx]==mp[y][x] && !chk[y][nx]) {
                            mp[y][nx]*=2;
                            chk[y][nx]=1;
                            mp[y][x]=0;
                        }
                        else if(mp[y][nx+1]==0) {
                            mp[y][nx+1]=mp[y][x];
                            mp[y][x]=0;
                        }
                    }
                    break;
                }
            }
            FOR(y,n) FOR(x,n) tmp[y][x]=mp[y][x];
            FOR(nDir,4) {
                dfs(nDir,cnt+1);
                FOR(y,n) FOR(x,n) mp[y][x]=tmp[y][x];
            }
        break;
        case 1://오
            FOR(y,n) for(int x=n-2;x>=0;--x) {
                if(mp[y][x]==0) continue;
                FORS(nx,x+1,n) {
                    if(mp[y][nx]==0) {
                        if(nx<n-1) continue;
                        mp[y][nx]=mp[y][x];
                        mp[y][x]=0;
                    }
                    else {
                        if(mp[y][nx]==mp[y][x] && !chk[y][nx]) {
                            mp[y][nx]*=2;
                            chk[y][nx]=1;
                            mp[y][x]=0;
                        }
                        else if(mp[y][nx-1]==0) {
                            mp[y][nx-1]=mp[y][x];
                            mp[y][x]=0;
                        }
                    }
                    break;
                }
            }
            FOR(y,n) FOR(x,n) tmp[y][x]=mp[y][x];
            FOR(nDir,4) {
                dfs(nDir,cnt+1);
                FOR(y,n) FOR(x,n) mp[y][x]=tmp[y][x];
            }
        break;
        case 2://위
            FOR(x,n) FORS(y,1,n) {
                if(mp[y][x]==0) continue;
                for(int ny=y-1;ny>=0;--ny) {
                    if(mp[y][x]==0) break;
                    if(mp[ny][x]==0) {
                        if(ny>0) continue;
                        mp[ny][x]=mp[y][x];
                        mp[y][x]=0;
                    }
                    else {
                        if(mp[ny][x]==mp[y][x] && !chk[ny][x]) {
                            mp[ny][x]*=2;
                            chk[ny][x]=1;
                            mp[y][x]=0;
                        }
                        else if(mp[ny+1][x]==0) {
                            mp[ny+1][x]=mp[y][x];
                            mp[y][x]=0;
                        }
                    }
                    break;
                }
            }
            FOR(y,n) FOR(x,n) tmp[y][x]=mp[y][x];
            FOR(nDir,4) {
                dfs(nDir,cnt+1);
                FOR(y,n) FOR(x,n) mp[y][x]=tmp[y][x];
            }
        break;
        case 3://아래
            FOR(x,n) for(int y=n-2;y>=0;--y) {
                if(mp[y][x]==0) continue;
                FORS(ny,y+1,n) {
                    if(mp[ny][x]==0) {
                        if(ny<n-1) continue;
                        mp[ny][x]=mp[y][x];
                        mp[y][x]=0;
                    }
                    else {
                        if(mp[ny][x]==mp[y][x] && !chk[ny][x]) {
                            mp[ny][x]*=2;
                            chk[ny][x]=1;
                            mp[y][x]=0;
                        }
                        else if(mp[ny-1][x]==0) {
                            mp[ny-1][x]=mp[y][x];
                            mp[y][x]=0;
                        }
                    }
                    break;
                }
            }
            FOR(y,n) FOR(x,n) tmp[y][x]=mp[y][x];
            FOR(nDir,4) {
                dfs(nDir,cnt+1);
                FOR(y,n) FOR(x,n) mp[y][x]=tmp[y][x];
            }
        break;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    FOR(y,n) FOR(x,n) cin>>mp[y][x];
    FOR(y,n) FOR(x,n) ori[y][x]=mp[y][x];
    FOR(dir,4) {
        dfs(dir,0);
        FOR(y,n) FOR(x,n) mp[y][x]=ori[y][x];
    }
    cout<<res;
}
