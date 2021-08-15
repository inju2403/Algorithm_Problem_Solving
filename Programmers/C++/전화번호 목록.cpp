#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

struct Trie {
    bool terminal;
    Trie *children[10];
    Trie(): terminal(false) {
        FOR(i,10) children[i] = nullptr;
    }
    ~Trie() {
        FOR(i,10) if(children[i]) delete children[i];
    }
    
    void insert(string& s,int idx) {
        if(idx==s.size()) terminal = true;
        else {
            int next = s[idx] - '0';
            if(children[next]==nullptr) children[next] = new Trie();
            children[next]->insert(s,idx+1);
        }
    }
    
    bool find(string& s,int idx) {
        if(idx == s.size()) return 0;
        if(terminal==true) return 1;
        int next = s[idx] - '0';
        if(children[next]==nullptr) return 0;
        return children[next]->find(s,idx+1);
    }
};

Trie *root;

bool solution(vector<string> phone_book) {
    root = new Trie();
    for(auto s: phone_book) {
        root->insert(s,0);
    }
    for(auto s: phone_book) {
        if(root->find(s,0)) return false;
    }
    
    return true;
}
