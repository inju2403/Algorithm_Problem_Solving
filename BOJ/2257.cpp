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

int idx,sum,st[MAX];
string s;
unordered_map<char, int> um;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    um['H']=1;
    um['C']=12;
    um['O']=16;
    cin>>s;
    FOR(i,s.size()) {
        char c = s[i];
        if(c=='(') {
            st[++idx]=0;
        }
        else if(c==')') {
            sum = st[idx--];
            st[idx] += sum;
        }
        else if(c>='2' && c<='9') {
            st[idx] += sum*(c-'0'-1);
        }
        else {
            sum = um[c];
            st[idx]+=um[c];
        }
    }
    cout<<st[0];
}
