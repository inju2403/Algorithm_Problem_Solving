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
#define LINF 2123456789123456789
#define MAX 21
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int q,w;
string s,a,b,tmp;

int gcd(int a,int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>s;
    FOR(i,s.size()+1) {
        if(i==s.size()) {
            b = tmp;
            break;
        }
        else if(s[i]==':') {
            a = tmp;
            tmp = "";
        }
        else tmp += s[i];
    }
    q = stoi(a);
    w = stoi(b);
    int d = gcd(q,w);
    cout<<q/d<<":"<<w/d;
}
