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
#define LINF 9123456789123456789
#define MAX 1005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

bool chk[22];
int n,x;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    while(n--) {
        cin>>s;
        if(s=="add") {
            cin>>x;
            if(x<0 || x>20) continue;
            chk[x]=1;
        }
        else if(s=="remove") {
            cin>>x;
            if(x<0 || x>20) continue;
            chk[x]=0;
        }
        else if(s=="check") {
            cin>>x;
            if(x<0 || x>20) continue;
            cout<<(chk[x]? 1 : 0)<<'\n';
        }
        else if(s=="toggle") {
            cin>>x;
            if(x<0 || x>20) continue;
            if(chk[x]) chk[x]=0;
            else chk[x]=1;
        }
        else if(s=="all") {
            memset(chk,1,sizeof(chk));
        }
        else if(s=="empty") {
            memset(chk,0,sizeof(chk));
        }
    }
}
