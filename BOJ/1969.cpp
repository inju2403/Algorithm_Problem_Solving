#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,l,mn;
vector<string> v;
string s;
unordered_map<char,int> um;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>l;
    v.resize(n);
    FOR(i,n) cin>>v[i];
    FOR(i,l) {
        int mx=0;
        char ch='Z';
        FOR(j,n) um[v[j][i]]++;
        FOR(j,n) if(um[v[j][i]] >= mx) {
            if(um[v[j][i]]>mx) ch = v[j][i];
            else if(um[v[j][i]]==mx && ch>v[j][i]) ch = v[j][i];
            mx = um[v[j][i]];
        }
        mn+=n-mx;
        s+=ch;
        um.clear();
    }
    cout<<s<<'\n'<<mn;
}
