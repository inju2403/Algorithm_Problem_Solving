#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,m,x,res;
unordered_map<int, int> um;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n>>m;
    FOR(i,n+m) {
        cin>>x;
        ++um[x];
    }
    for(auto &i: um) if(i.second==1) ++res;
    cout<<res;
}
