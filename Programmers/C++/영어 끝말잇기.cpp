#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

char pre;
unordered_map<string,bool> um;

vector<int> solution(int n, vector<string> words) {
    vector<int> res;
    res.push_back(0);
    res.push_back(0);

    pre = words[0][words[0].size()-1];
    um[words[0]]=1;
    FORS(i,1,words.size()) {
        char c = words[i][0];
        if(pre!=c || um.count(words[i])) {
            res.clear();
            res.push_back((i+1)%n ? (i+1)%n : n);
            res.push_back(i/n+1);
            break;
        }
        um[words[i]]=1;
        pre = words[i][words[i].size()-1];
    }
    return res;
}
