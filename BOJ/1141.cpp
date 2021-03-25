#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,o;
vector<string> v;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    v.resize(n);
    FOR(i,n) cin>>v[i];
    sort(v.begin(),v.end());
    FOR(i,n) {
        bool chk=0;
        FORS(j,i+1,n) {
            if(v[j].find(v[i])==0) {
                chk=1;
                break;
            }
        }
        if(chk) ++o;
    }
    cout<<n-o;
}
