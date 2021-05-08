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

ll n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    cout<<((n%5==0 || n%5==2)? "CY" : "SK");
}
