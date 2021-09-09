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

int n,k;
vector<int> v,tmp;

void merge(int l, int r) {
    if( n/(r-(l-1)) < k) return;
    int mid = (l+r) / 2;
    int i = l, j = mid+1, k = l;
    while(i<=mid && j<=r) {
        if(v[i]<=v[j]) tmp[k++] = v[i++];
        else tmp[k++] = v[j++];
    }
    while(i<=mid) tmp[k++] = v[i++];
    while(j<=r) tmp[k++] = v[j++];
    FORS(idx,l,r+1) v[idx] = tmp[idx];
}

void mergeSort(int l, int r) {
    if(l<r) {
        int mid = (l+r) / 2;
        mergeSort(l,mid);
        mergeSort(mid+1,r);
        merge(l,r);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    v.resize(n); tmp.resize(n);
    FOR(i,n) cin>>v[i];
    cin>>k;
    mergeSort(0,n-1);
    FOR(i,n) cout<<v[i]<<" ";
}
