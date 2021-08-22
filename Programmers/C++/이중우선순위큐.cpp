#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int cnt;
priority_queue<int> mxQ,mnQ;
vector<int> res;

vector<int> solution(vector<string> operations) {
    
    for(auto x: operations) {
        char c = x[0];
        int num = stoi(x.substr(2));
        if(c=='I') {
            mxQ.push(num);
            mnQ.push(-num);
            ++cnt;
        }
        else {
            if(cnt==0) continue;
            if(cnt==1) {
                --cnt;
                priority_queue<int> emptyQ1,emptyQ2;
                swap(mxQ, emptyQ1);
                swap(mnQ, emptyQ2);
                continue;
            }
            if(num==1) mxQ.pop();
            else if(num==-1) mnQ.pop();
            --cnt;
        }
    }
    if(cnt) {
        res.push_back(mxQ.top());
        res.push_back(-mnQ.top());
    }
    else {
        res.push_back(0);
        res.push_back(0);
    }
    
    return res;
}
