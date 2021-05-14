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
#define MAX 10010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,k,res;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    v.resize(n);
    FOR(i,n) cin>>v[i];
    
    int l=0, r=n*20+1;
    while(l<=r) {
        // mid: 문제 개수 합의 최솟값
        // 최솟값이하로 개수를 쪼갰을 때, 그 개수가 k를 초과하면 l을 올리고 반대면 r을 내린다.
        int mid = (l+r)/2;
        int sum = 0, group = 0;
        FOR(i,n) {
            sum+=v[i];
            if(sum>=mid) {
                sum=0;
                ++group;
            }
        }
        if(group>=k) {
            l=mid+1;
            res=max(res,mid);
        }
        else r=mid-1;
    }
    cout<<res;
}
