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
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

struct node {
    string name;
    int d,m,y;
    bool operator < (const node& arg) const {
        if(y==arg.y) {
            if(m==arg.m) return d<arg.d;
            else return m<arg.m;
        }
        return y<arg.y;
    }
};

int n;
vector<node> v;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    v.resize(n);
    FOR(i,n) cin>>v[i].name>>v[i].d>>v[i].m>>v[i].y;
    sort(v.begin(),v.end());
    cout<<v[n-1].name<<'\n'<<v[0].name;
}
