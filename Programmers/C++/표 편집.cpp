#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 1000005
using namespace std;

struct node {
    int idx;
    node *left, *right;
    node(int i): idx(i) {
        left = nullptr;
        right = nullptr;
    }
};
vector<node*> v;
stack<node*> st;

string res;

string solution(int n, int k, vector<string> cmd) {
    v.resize(n);
    FOR(i,n) v[i] = new node(i);
    v[0]->right = v[1];
    v[n-1]->left = v[n-2];
    FORS(i,1,n-1) {
        v[i]->left = v[i-1];
        v[i]->right = v[i+1];
    }
    
    for(auto x: cmd) {
        if(x[0]=='U') {
            int move = stoi(x.substr(2,x.size()-2));
            while(move--) k = v[k]->left->idx;
        } else if(x[0]=='D') {
            int move = stoi(x.substr(2,x.size()-2));
            while(move--) k = v[k]->right->idx;
        } else if(x[0]=='C') {
            st.push(v[k]);
            if(v[k]->left!=nullptr) v[k]->left->right = v[k]->right;
            if(v[k]->right!=nullptr) {
                v[k]->right->left = v[k]->left;
                k = v[k]->right->idx;
            } else k = v[k]->left->idx;
        } else if(x[0]=='Z') {
            node* back = st.top();
            st.pop();
            if(back->left!=nullptr) back->left->right = back;
            if(back->right!=nullptr) back->right->left = back;
        }
    }
    while(!st.empty()) {
        node* x = st.top();
        st.pop();
        x->idx = -1;
    }
    for(auto x: v) x->idx==-1? res+='X' : res+='O';
    
    return res;
}
