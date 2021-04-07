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
    int idx,num,val;
};

int n,cnt;
vector<node> v;

bool comp1(node& a, node& b) {
    return a.val<b.val;
}

bool comp2(node& a, node& b) {
    return a.idx<b.idx;
}

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    v.resize(n);
    FOR(i,n) {
        cin>>v[i].val;
        v[i].idx=i;
    }
    sort(v.begin(),v.end(),comp1);
    FORS(i,1,n) v[i].val==v[i-1].val? v[i].num=cnt :v[i].num=++cnt;
    sort(v.begin(),v.end(),comp2);
    FOR(i,n) cout<<v[i].num<<" ";
}
