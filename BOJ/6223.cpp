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
#define MAX 10010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

struct node {
    int val, idx;
    bool operator < (const node& arg) const {
        return val < arg.val;
    }
};

int n,res,cycle;
bool chk[MAX];
vector<node> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    v.resize(n);
    FOR(i,n) {
        cin>>v[i].val;
        v[i].idx=i;
    }
    sort(v.begin(), v.end());
    FOR(i,n) {
        if(chk[i]) continue; //이미 방문한 사이클에 포함되면 continue
        int j=i;
        cycle=0; //사이클의 크기
        while(!chk[j]) { //사이클을 한바퀴 돌았으면 탈출
            chk[j]=1;
            res+=v[j].val;
            ++cycle;
            
            j=v[j].idx;
        }
        res+=min(v[i].val*(cycle-2), v[0].val*cycle + (v[0].val+v[i].val));
    }
    cout<<res;
}
