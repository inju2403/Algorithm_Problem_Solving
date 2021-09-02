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
#define MAX 105
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

struct node {
    int d,c;
    bool operator < (const node& arg) const {
        if(d!=arg.d) return d<arg.d;
        return c>arg.c;
    }
};

int n,res,d,c;
vector<node> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    while(n--) {
        cin>>d>>c;
        v.push_back({d,c});
    }
    FOR(i,v.size()) {
        bool chk = 1;
        FOR(j,v.size()) {
            if(i==j) continue;
            if(v[j].d < v[i].d) {
                if(v[j].c <= v[i].c) {
                    chk=0;
                    break;
                }
            }
            if(v[j].c < v[i].c) {
                if(v[j].d <= v[i].d){
                    chk=0;
                    break;
                }
            }
        }
        if(chk) ++res;
    }
    cout<<res;
}
