#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

int n,mx;
string s,res;
unordered_map<string, int> um;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    while(n--) {
        cin>>s;
        ++um[s];
    }
    for(auto x: um) mx=max(mx,x.second);
    for(auto x: um) if(mx==x.second && (res=="" || x.first<res)) res=x.first;
    cout<<res;
}
