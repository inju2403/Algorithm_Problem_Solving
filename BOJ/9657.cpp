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
#define MAX 1010
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,d[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    
    // 1: 첫 턴 이김, 0: 다음 턴 이김
    d[1]=d[3]=d[4]=1;
    FORS(i,5,n+1) if(d[i-1]==0 || d[i-3]==0 || d[i-4]==0) d[i]=1;
    cout<<(d[n]? "SK" : "CY");
}
