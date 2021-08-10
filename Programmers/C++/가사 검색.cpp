#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

struct Trie {
    int cnt;
    Trie* children[26];
    Trie(): cnt(0) {
        memset(children,0,sizeof(children));
    }
    ~Trie() {
        FOR(i,26) if(children[i]) delete children[i];
    }
    
    void insert(string& s, int idx) {
        ++cnt;
        if(idx==s.size()) return;
        else {
            int next = s[idx]-'a';
            if(children[next]==NULL) children[next] = new Trie();
            children[next]->insert(s,idx+1);
        }
    }
    
    int find(string& s, int idx) {
        if(s[idx]=='?' || s.size()==idx) return cnt;
        int next = s[idx]-'a';
        if(children[next]==NULL) return 0;
        return children[next]->find(s,idx+1);
    }
    
};

Trie a[10005], b[10005];


vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> res;
    
    for(auto x: words) {
        a[x.size()].insert(x,0);
        reverse(x.begin(),x.end());
        b[x.size()].insert(x,0);
    }
    
    for(auto x: queries) {
        if(x[0]!='?') res.push_back(a[x.size()].find(x,0));
        else {
            reverse(x.begin(),x.end());
            res.push_back(b[x.size()].find(x,0));
        }
    }
    
    return res;
}
