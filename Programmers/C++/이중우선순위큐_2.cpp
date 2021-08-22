#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

multiset<int> pq;
multiset<int>::iterator iter;
vector<int> res;

vector<int> solution(vector<string> operations) {
    
    for(auto x: operations) {
        char c = x[0];
        int num = stoi(x.substr(2));
        if(c=='I') {
            pq.insert(num);
        }
        else {
            if(pq.empty()) continue;
            if(num==1) pq.erase(--pq.end());
            else if(num==-1) pq.erase(pq.begin());
        }
    }
    if(pq.size()) {
        iter = --pq.end(); res.push_back(*iter);
        iter = pq.begin(); res.push_back(*iter);
    }
    else {
        res.push_back(0);
        res.push_back(0);
    }
    
    return res;
}
