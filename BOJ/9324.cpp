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

unordered_map<char, int> um;
int n;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    while(n--) {
        um.clear();
        bool chk = 1;
        cin>>s;
        FOR(i,s.size()) {
            if(++um[s[i]]==3) {
                if(i==s.size()-1 || s[i]!=s[i+1]) {
                    chk=0;
                    break;
                }
                else um[s[i++]]=0;
            }
        }
        cout<<(chk? "OK\n" : "FAKE\n");
    }
}
