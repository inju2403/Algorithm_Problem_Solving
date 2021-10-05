#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321

using namespace std;

int mx,mn=INF,sum,sz;
string res;

string solution(vector<vector<int>> scores) {
    int n = scores.size();
    FOR(i,n) {
        sum = 0;
        sz = n;
        mx = 0;
        mn = INF;
        FOR(j,n) {
            mx = max(mx, scores[j][i]);
            mn = min(mn, scores[j][i]);
            sum += scores[j][i];
        }
        int mxCnt=0,mnCnt=0;
        FOR(j,n) if(mx==scores[j][i]) if(++mxCnt>1) break;
        FOR(j,n) if(mn==scores[j][i]) if(++mnCnt>1) break;
        if((mxCnt==1&&scores[i][i]==mx)||(mnCnt==1&&scores[i][i]==mn)) {
            sum -= scores[i][i];
            --sz;
        }
        sum /= sz;
        char ch = 'F';
        if(sum>=90) ch = 'A';
        else if(sum>=80) ch = 'B';
        else if(sum>=70) ch = 'C';
        else if(sum>=50) ch = 'D';
        res+=ch;
    }
    return res;
}
