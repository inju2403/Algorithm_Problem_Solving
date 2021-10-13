#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define LINF 9123456789123456789
#define MAX 1010
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,k,cnt,stIdx,res;
vector<int> belt;
vector<bool> robot;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    belt.resize(2*n); robot.resize(2*n, 0);
    FOR(i,2*n) cin>>belt[i];
    while(cnt<k) {
        ++res;
        //1.벨트, 로봇 돌리기
        --stIdx;
        if(stIdx==-1) stIdx=2*n-1;
        
        //2. 로봇 내리기
        robot[(stIdx+n-1)%(2*n)] = 0;
        
        //3. 로봇 이동
        for(int i = (stIdx + n-1)-1; i>=stIdx; --i) {
            int idx = i%(2*n);
            int nIdx = (i+1)%(2*n);
            if(robot[idx] && robot[nIdx]==0 && belt[nIdx]>0) {
                robot[nIdx] = 1;
                robot[idx] = 0;
                if(--belt[nIdx]==0) ++cnt;
            }
        }
        
        //4. 로봇 올리기
        if(belt[stIdx]>0 && robot[stIdx]==0) {
            if(--belt[stIdx]==0) ++cnt;
            robot[stIdx] = 1;
        }
        
        //5. 로봇 내리기
        robot[(stIdx+n-1)%(2*n)] = 0;
    }
    cout<<res;
}
