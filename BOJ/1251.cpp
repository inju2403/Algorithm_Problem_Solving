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
#define MAX 105
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

string s,res;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>s;
    FORS(i,1,s.size()) {
        FORS(j,i+1,s.size()) {
            string a = s.substr(0,i);
            string b = s.substr(i,j-i);
            string c = s.substr(j,s.size()-j);
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            a = a+b+c;
            if(res=="") res=a;
            else {
                if(res>a) res = a;
            }
        }
    }
    cout<<res;
}
