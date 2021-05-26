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
#define MAX 10005
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,m,res,idx=INF;
bool chk[MAX];
vector<int> ship,box;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    ship.resize(n);
    FOR(i,n) cin>>ship[i];
    sort(ship.begin(),ship.end(),greater<int>());
    
    cin>>m;
    box.resize(m);
    FOR(i,m) cin>>box[i];
    sort(box.begin(),box.end(),greater<int>());
    
    if(ship[0]<box[0]) {
        cout<<-1;
        return 0;
    }
    int j=0;
    while (j<m) {
        bool judge=0;
        FOR(i,n) {
            if(j>=m) break;
            if(ship[i]>=box[j]) {
                while(chk[j]) ++j;
                chk[j++]=1;
                continue;
            }
            else {
                if(!judge) judge=1, idx=j;
                while(ship[i]<box[j]) ++j;
                while(chk[j]) ++j;
                chk[j]=1;
            }
        }
        if(judge) j=idx;
        ++res;
    }
    cout<<res;
}
