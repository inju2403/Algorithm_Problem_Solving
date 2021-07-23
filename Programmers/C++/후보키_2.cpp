#include <iostream>
#include <string>
#include <vector>
#include <set>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int res,col,row;
set<string> st;
vector<int> v;

bool judge(int i) {
    for(auto x: v) if((x&i) == x) return false;
    return true;
}

int solution(vector<vector<string>> relation) {
    
    col = relation[0].size();
    row = relation.size();
    
    FORS(i, 1, 1<<col) {
        st.clear();
        FOR(y, row) {
            string cur = "";
            FOR(x, col) {
                //선택한 컬럼 중에 하나면
                if(i & (1<<x)) cur += relation[y][x];
            }
            st.insert(cur);
        }
        if(st.size()==row && judge(i)) {
            v.push_back(i);
        }
    }
    
    return v.size();
}
