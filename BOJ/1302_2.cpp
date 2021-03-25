#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,mx;
string s,res;
vector<string> v;
unordered_map<string, int> um;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    while(n--) {
        cin>>s;
        if(!um[s]) v.push_back(s);
        ++um[s];
    }
    FOR(i,v.size()) mx=max(mx,um[v[i]]);
    FOR(i,v.size()) if(um[v[i]]==mx && (res=="" || v[i]<res)) res=v[i];
    cout<<res;
}
