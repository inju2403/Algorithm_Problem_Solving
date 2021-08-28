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
#define MAX 21
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,cnt;
vector<int> ori,v;
unordered_map<int,int> idx;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    ori.resize(n); v.resize(n);
    FOR(i,n) {
        cin>>ori[i];
        idx[ori[i]]=i;
    }
    FOR(i,n) cin>>v[i];
    FOR(i,n) {
        int index = idx[v[i]];
        if(index==i) continue;
        swap(ori[index], ori[i]);
        idx[ori[index]] = index;
        ++cnt;
    }
    cout<<(cnt%2? "Impossible\n" : "Possible\n");
}
