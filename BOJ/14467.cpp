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
#define MAX 105
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,a,b,res,pos[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    memset(pos,-1,sizeof(pos));
    while(n--) {
        cin>>a>>b;
        if(pos[a]==-1) pos[a]=b;
        else {
            if(pos[a]!=b) {
                ++res;
                pos[a]=b;
            }
        }
    }
    cout<<res;
}
