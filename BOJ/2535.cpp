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

struct student {
    int n1,n2,score;
    bool operator < (const student &arg) const {
        return score > arg.score;
    }
};

int n,a,b,s,cnt,idx;
vector<student> v;
unordered_map<int, int> mp;

int main() {
    ios::sync_with_stdio(); cin.tie(0);
    cin>>n;
    FOR(i,n) {
        cin>>a>>b>>s;
        v.push_back({a,b,s});
    }
    sort(v.begin(), v.end());
    while(cnt<3) {
        if(mp[v[idx].n1]<2) {
            cout<<v[idx].n1<<" "<<v[idx].n2<<'\n';
            ++cnt;
            ++mp[v[idx].n1];
            ++idx;
        }
        else ++idx;
    }
}
