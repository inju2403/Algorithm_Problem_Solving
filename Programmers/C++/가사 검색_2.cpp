#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

struct Trie {
    unordered_map<int,int> um;
    Trie* children[26];
    Trie() {
        memset(children,0,sizeof(children));
    }
    ~Trie() {
        FOR(i,26) if(children[i]) delete children[i];
    }
    
    void insert(string& s, int idx) {
        ++um[s.size()];
        if(idx==s.size()) return;
        else {
            int next = s[idx]-'a';
            if(children[next]==NULL) children[next] = new Trie();
            children[next]->insert(s,idx+1);
        }
    }
    
    int find(string& s, int idx) {
        if(s[idx]=='?' || s.size()==idx) return um[s.size()];
        int next = s[idx]-'a';
        if(children[next]==NULL) return 0;
        return children[next]->find(s,idx+1);
    }
    
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> res;
    
    Trie* root1 = new Trie();
    Trie* root2 = new Trie();
    
    for(auto x: words) {
        root1->insert(x,0);
        reverse(x.begin(),x.end());
        root2->insert(x,0);
    }
    
    for(auto x: queries) {
        if(x[0]!='?') res.push_back(root1->find(x,0));
        else {
            reverse(x.begin(),x.end());
            res.push_back(root2->find(x,0));
        }
    }
    
    return res;
}
