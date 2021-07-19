#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int res;
bool visited[10],chk[1000];
vector<string> v;

void dfs(int num,vector<string>& v,vector<string>& u,vector<string>& b) {
    if(v.size()==b.size()) {
        if(chk[num]) return;
        bool judge=1;
        FOR(i,b.size()) {
            if(v[i].size()!=b[i].size()) {
                judge=0;
                break;
            }
            FOR(j,b[i].size()) {
                if(b[i][j]=='*') continue;
                if(v[i][j]!=b[i][j]) {
                    judge=0;
                    break;
                }
            }
            if(judge==0) break;
        }
        if(judge) ++res, chk[num]=1;
        return;
    }
    FOR(i,u.size()) {
        if(visited[i]) continue;
        visited[i]=1; v.push_back(u[i]);
        dfs(num+(1<<i),v,u,b);
        visited[i]=0; v.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    dfs(0,v,user_id,banned_id);
    
    return res;
}
