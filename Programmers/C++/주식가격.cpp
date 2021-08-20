#include <string>
#include <vector>
#include <stack>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;
typedef pair<int,int> pii;

int idx,sz;
stack<pii> st;
vector<int> res;

vector<int> solution(vector<int> prices) {
    
    sz=prices.size();
    res.resize(sz);
    
    st.push({prices[0],0});
    FORS(i,1,sz) {
        int cur = prices[i];
        while(!st.empty()) {
            pii top = st.top();
            if(cur<top.first) {
                res[top.second]=i-top.second;
                st.pop();
            }
            else break;
        }
        st.push({cur,i});
    }
    while(!st.empty()) {
        int top = st.top().second;
        res[top] = (sz-1) - top;
        st.pop();
    }
    return res;
}
