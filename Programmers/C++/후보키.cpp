#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

unordered_map<string,bool> um,cur;
int res,col,row;
vector<int> v;

bool chk(int idx, int cnt, string& cur,string& ori) {
    
    if(cur.size()==cnt) {
        if(um.count(cur)) return false;
        else return true;
    }
    FORS(i,idx,ori.size()) {
        cur+=ori[i];
        if(chk(i+1,cnt,cur,ori)==0) return false;
        cur.pop_back();
    }
    return true;
}

void dfs(int idx, int cnt, vector<int>& v, vector<vector<string>>& r) {
    if(cnt==v.size()) {
        cur.clear();
        FOR(y,row) {
            string s = "";
            for(auto x: v) s+=r[y][x];
            if(cur.count(s)) return;
            cur[s]=1;
        }
        // 컬럼 조합의 부분집합중에 체크된게 있는지 확인
        string s = "";
        for(auto x: v) s+=to_string(x);
        
        bool judge = 1;
        FORS(i,1,s.size()+1) {
            string em = "";
            if(chk(0,i,em,s)==0) {
                judge = 0;
                break;
            }
        }
        if(judge) um[s]=1, ++res;
        return;
    }
    FORS(i,idx,col) {
        v.push_back(i);
        dfs(i+1,cnt,v,r);
        v.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    
    col = relation[0].size();
    row = relation.size();
    
    FORS(i,1,col+1) {
        //nCi
        dfs(0,i,v,relation);
    }
    
    return res;
}
