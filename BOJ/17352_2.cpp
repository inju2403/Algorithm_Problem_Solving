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
#define MAX 300010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,a,b,parent[MAX];

int getParent(int x) {
    return x == parent[x]? x : parent[x]=getParent(parent[x]);
}

void merge(int a,int b) {
    a = getParent(a), b = getParent(b);
    a < b? parent[b]=a : parent[a]=b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    FORS(i,1,n+1) parent[i]=i;
    FOR(i,n-2) {
        cin>>a>>b;
        if(getParent(a)!=getParent(b)) {
            merge(a,b);
        }
    }
    FORS(i,2,n+1) if(getParent(i)!=1) {
        cout<<"1 "<<i;
        break;
    }
}
