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
#define MAX 1010
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int tc,n,idx[MAX];
vector<int> preorder, inorder;

void solve(int preS,int preE,int inS,int inE) {
    if(preS>preE || inS>inE) return;
    int rootIdx = idx[preorder[preS]];
    int sz = rootIdx - inS;
    solve(preS+1, (preS+1)+(sz-1), inS, rootIdx-1);
    solve((preS+1)+sz, preE, rootIdx+1, inE);
    cout<<inorder[rootIdx]<<" ";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        memset(idx,0,sizeof(idx)); preorder.clear(); inorder.clear();
        cin>>n;
        preorder.resize(n); inorder.resize(n);
        FOR(i,n) cin>>preorder[i];
        FOR(i,n) {
            cin>>inorder[i];
            idx[inorder[i]] = i;
        }
        solve(0,n-1,0,n-1);
        cout<<'\n';
    }
}
