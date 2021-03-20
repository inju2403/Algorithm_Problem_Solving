#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int i,c1,c2;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>s;
    while(i<s.size()) {
        if(s[i]=='1') {
            ++i;
            continue;
        }
        while(s[i]!='1'&&i<s.size()) ++i;
        ++c1;
    }
    i=0;
    while(i<s.size()) {
        if(s[i]=='0') {
            ++i;
            continue;
        }
        while(s[i]!='0'&&i<s.size()) ++i;
        ++c2;
    }
    cout<<min(c1,c2);
}
