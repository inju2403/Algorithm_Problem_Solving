#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int cnt;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>s;
    FOR(i,s.size()-1) {
        if(s[i]!=s[i+1]) ++cnt;
    }
    cout<<(cnt+1)/2;
}
