#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll before,sum,idx;
priority_queue<pll> pq;
vector<pll> v;

bool comp(pll a, pll b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    
    FOR(i,food_times.size()) {
        int t = food_times[i];
        pq.push({-t,i});
        sum+=food_times[i];
    }
    if(k>=sum) return -1;
    
    while(!pq.empty()) {
        ll cost = -pq.top().first;
        ll idx = pq.top().second;
        
        ll val = (cost-before)*pq.size();
        if(val>k) break;
        k-=val;
        before = cost;
        pq.pop();
    }
    while(!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }
    sort(v.begin(),v.end(),comp);
    idx = v[k%v.size()].second+1;
    
    return idx;
}
