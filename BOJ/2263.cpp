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

int n,idx[MAX];
vector<int> inorder,postorder;

void solve(int inS, int inE, int poS, int poE) {
    if(inS>inE || poS>poE) return;
    int rootIdx = idx[postorder[poE]];
    int sz = rootIdx - inS;
    cout<<inorder[rootIdx]<<" ";
    solve(inS, rootIdx-1, poS, poS+sz-1);
    solve(rootIdx+1, inE, poS+sz, poE-1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    inorder.resize(n); postorder.resize(n);
    FOR(i,n) {
        cin>>inorder[i];
        idx[inorder[i]]=i;
    }
    FOR(i,n) cin>>postorder[i];
    solve(0,n-1,0,n-1);
}
