#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

vector<int> buff;
int bufi,x1,x2,y1,y2,num=1;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> v;
    v.resize(rows);
    FOR(y,rows) FOR(x,columns) v[y].push_back(num++);
    vector<int> answer;
    
    FOR(i,queries.size()) {
        y1 = queries[i][0]-1;
        x1 = queries[i][1]-1;
        y2 = queries[i][2]-1;
        x2 = queries[i][3]-1;
        buff.clear();
        bufi = 0;
        
        // 반시계방향으로 buff에 넣기
        int n=y1, m=x1;
        FOR(j,y2-y1) buff.push_back(v[n++][m]);
        FOR(j,x2-x1) buff.push_back(v[n][m++]);
        FOR(j,y2-y1) buff.push_back(v[n--][m]);
        FOR(j,x2-x1) buff.push_back(v[n][m--]);
        
        // min값 일단 구해서 넣어줌
        int mn = 987654321;
        FOR(j,buff.size()) mn=min(mn,buff[j]);
        answer.push_back(mn);
        
        // 돌리기
        rotate(buff.begin(),buff.begin()+1,buff.end());
        
        // 다시 넣어줌
        n=y1; m=x1;
        FOR(j,y2-y1) v[n++][m] = buff[bufi++];
        FOR(j,x2-x1) v[n][m++] = buff[bufi++];
        FOR(j,y2-y1) v[n--][m] = buff[bufi++];
        FOR(j,x2-x1) v[n][m--] = buff[bufi++];
    }
    
    return answer;
}
