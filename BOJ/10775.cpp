#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 100001
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int g,p,x,gate,res,parent[MAX];

int getParent(int x) {
    return x==parent[x]? x : parent[x]=getParent(parent[x]);
}

void merge(int a,int b) {
    a=getParent(a), b=getParent(b);
    a<b? parent[b]=a : parent[a]=b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>g>>p;
    FORS(i,1,g+1) parent[i]=i;
    while(p--) {
        cin>>x;
        gate=getParent(x);
        if(gate==0) break;
        else {
            ++res;
            merge(gate-1,gate);
        }
    }
    cout<<res;
}
