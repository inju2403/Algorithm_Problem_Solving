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
#define MAX 1005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int isPal(string s) {
    int ret = 0,  left = 0, right = s.size()-1;
    
    while(left<=right) {
        if(s[left]==s[right]) {
            ++left;
            --right;
        }
        else {
            int l = left + 1, r = right;
            while(l<r) {
                if(s[l]!=s[r]) {
                    ++ret;
                    break;
                }
                ++l; --r;
            }
            l = left; r = right - 1;
            while(l<r) {
                if(s[l]!=s[r]) {
                    ++ret;
                    break;
                }
                ++l; --r;
            }
            return ret==0? 1 : ret;
        }
    }
    return ret;
}

int tc;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        cin>>s;
        cout<<isPal(s)<<'\n';
    }
}
