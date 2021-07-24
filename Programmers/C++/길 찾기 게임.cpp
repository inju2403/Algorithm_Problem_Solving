#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

struct node {
    int x,y,idx;
    node* left;
    node* right;
    
    bool operator < (const node& arg) const {
        if(y!=arg.y) return y>arg.y;
        return x<arg.x;
    }
};
node* root;
vector<node> tree;
vector<int> res1,res2;

void go(node* root, node* child) {
    if(root->x > child->x) {
        if(root->left==nullptr) {
            root->left = child;
            return;
        }
        go(root->left,child);
    }
    else {
        if(root->right==nullptr) {
            root->right = child;
            return;
        }
        go(root->right,child);
    }
}

void preorder(node* root) {
    if(root==nullptr) return;
    res1.push_back(root->idx);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    res2.push_back(root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> res;
    
    FOR(i,nodeinfo.size()) {
        int cx = nodeinfo[i][0];
        int cy = nodeinfo[i][1];
        tree.push_back({cx,cy,i+1,nullptr,nullptr});
    }
    sort(tree.begin(),tree.end());
    root = &tree[0];
    FORS(i,1,tree.size()) go(root,&tree[i]);
    
    preorder(root);
    postorder(root);
    res.push_back(res1); res.push_back(res2);
    return res;
}
