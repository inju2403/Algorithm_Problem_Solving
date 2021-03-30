#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,m,t;
string s1,s2;
unordered_map<char, bool> mp;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n>>m;
    cin>>s1>>s2;
    cin>>t;
    reverse(s1.begin(), s1.end());
    FOR(i,s1.size()) mp[s1[i]] = 1;
    s1 += s2;
    while(t>0) {
        FOR(i,s1.size()-1) {
            if(i==s1.size()-1) break;
            if(mp[s1[i]]==1) {
                if(mp[s1[i+1]]==0) {
                    swap(s1[i],s1[i+1]);
                    ++i;
                }
            }
        }
        --t;
    }
    cout<<s1<<'\n';
}
