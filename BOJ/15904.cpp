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
#define LINF 9123456789123456789
#define MAX 21
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int idx;
string a = "UCPC", s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    getline(cin, s);
    for(char x: s) {
        if(x==a[idx]) ++idx;
    }
    cout<<(idx==4? "I love UCPC" : "I hate UCPC");
}
