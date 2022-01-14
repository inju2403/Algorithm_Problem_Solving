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
#define MAX 100010
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,m,k,a,b,inDegree[MAX];
unordered_map<int, int> um;
vector<int> adj[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>k;
    while(m--) {
        cin>>a>>b;
        adj[a].push_back(b);
        ++inDegree[b];
    }
    while(k--) {
        cin>>a>>b;
        if(a==1) {
            if(inDegree[b]>0) {
                cout<<"Lier!";
                return 0;
            }
            if(++um[b] == 1) {
                for(auto x: adj[b]) {
                    --inDegree[x];
                }
            }
        }
        else {
            if(um.count(b)==0) {
                cout<<"Lier!";
                return 0;
            }
            if(--um[b]==0) {
                um.erase(b);
                for(auto x: adj[b]) {
                    ++inDegree[x];
                }
            }
        }
    }
    cout<<"King-God-Emperor";
}
