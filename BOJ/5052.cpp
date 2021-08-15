#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define LINF 2123456789123456789
#define MAX 10005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

struct Trie {
    bool terminal;
    Trie* children[11];
    
    Trie(): terminal(false) {
        memset(children,0,sizeof(children));
    }
    ~Trie() {
        FOR(i,11) if(children[i]) delete children[i];
    }
    
    void insert(string& s,int idx) {
        if(idx==s.size()) terminal=true;
        else {
            int next = s[idx]-'0';
            if(children[next]==NULL) children[next] = new Trie();
            children[next]->insert(s,idx+1);
        }
    }
    
    bool find(string& s,int idx) {
        if(idx==s.size()) return false;
        if(terminal) return true;
        int next = s[idx]-'0';
        if(children[next]==NULL) return false;
        return children[next]->find(s,idx+1);
    }
    
};

int tc,n;
vector<string> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>tc;
    while(tc--) {
        cin>>n;
        v.resize(n);
        Trie* root = new Trie();
        FOR(i,n) {
            cin>>v[i];
            root->insert(v[i],0);
        }
        bool chk=1;
        FOR(i,v.size()) {
            if(root->find(v[i],0)) {
                chk=0;
                break;
            }
        }
        cout<<(chk? "YES" : "NO")<<'\n';
    }
    
}
