#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

int n,cnt,d;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>d;
    FORS(i,1,n+1) {
        int num=i;
        while(num) {
            if(num%10==d) ++cnt;
            num/=10;
        }
    }
    cout<<cnt;
}
