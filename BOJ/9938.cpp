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
#define MAX 300001
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,l,a,b,parent[MAX];
bool store[MAX];

int getParent(int x) {
    return x==parent[x]? x : parent[x]=getParent(parent[x]);
}

void merge(int a,int b) {
    a=getParent(a), b=getParent(b);
    parent[a]=b;
    cout<<"LADICA"<<'\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>l;
    FORS(i,1,l+1) parent[i]=i;
    FOR(i,n) {
        cin>>a>>b;
        if(store[a]==0) {
            store[a]=1;
            merge(a,b);
        }
        else if(store[b]==0) {
            store[b]=1;
            merge(b,a);
        }
        else if(store[getParent(a)]==0) {
            store[getParent(a)]=1;
            merge(a,b);
        }
        else if(store[getParent(b)]==0) {
            store[getParent(b)]=1;
            merge(b,a);
        }
        else cout<<"SMECE"<<'\n';
    }
}
