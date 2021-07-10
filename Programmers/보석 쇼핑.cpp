#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=0;i<(n);++i)

using namespace std;

set<string> st;
unordered_map<string,int> mp;
int cnt,total,mn=987654321;

vector<int> solution(vector<string> gems) {
    vector<int> res;
    int l=0, r=0;
    
    FOR(i,gems.size()) st.insert(gems[i]);
    total=st.size();
    
    
    while(!((r==gems.size()) && cnt<total)) {
        if(cnt==total) {
            if(--mp[gems[l++]]==0) --cnt;
        }
        else {
            if(++mp[gems[r++]]==1) ++cnt;
        }
        
        if(cnt==total) {
            if(r-l<mn) {
                mn=r-l;
                res.clear(); res.push_back(l+1); res.push_back(r);
            }
        }
    }
    
    return res;
}
