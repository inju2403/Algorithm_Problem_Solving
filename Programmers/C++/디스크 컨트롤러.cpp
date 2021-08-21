#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

struct node {
    int st,len;
    bool operator < (const node& arg) const {
        return len > arg.len;
    }
};

bool comp(vector<int> a, vector<int> b){
    if(a[0]!=b[0]) return a[0]<b[0];
    return a[1]<b[1];
}

int res,t;
queue<node> q;
priority_queue<node> pq;

int solution(vector<vector<int>> jobs) {
    
    sort(jobs.begin(),jobs.end(),comp);
    for(auto x: jobs) q.push({x[0],x[1]});
    
    node cur = q.front(); q.pop();
    pq.push(cur);
    t = cur.st;
    
    while(!pq.empty()) {
        node cur = pq.top(); pq.pop();
        t += cur.len;
        res += t - cur.st;
        
        while(!q.empty()) {
            node next = q.front();
            if(next.st > t) {
                if(pq.empty()) {
                    t = next.st;
                    pq.push(next); q.pop();
                }
                break;
            }
            pq.push(next); q.pop();
        }
    }
    
    return res/jobs.size();
}
