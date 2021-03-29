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

int n,x;
priority_queue<pii> pq;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    while(n--) {
        cin>>x;
        if(x==0) {
            if(pq.empty()) cout<<0<<'\n';
            else {
                cout<<-pq.top().second<<'\n';
                pq.pop();
            }
        }
        else {
            pq.push({-abs(x),-x});
        }
    }
}
