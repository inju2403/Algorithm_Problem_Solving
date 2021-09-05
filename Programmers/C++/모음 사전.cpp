#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int res;
char ch[5];
vector<string> v;

void dfs(int cnt,vector<int>& cur) {
    if(cur.size()==cnt) {
        string s = "";
        for(int i: cur) s+=ch[i];
        v.push_back(s);
        return;
    }
    FOR(i,5) {
        cur.push_back(i);
        dfs(cnt,cur);
        cur.pop_back();
    }
}

int solution(string word) {
    ch[0] = 'A';
    ch[1] = 'E';
    ch[2] = 'I';
    ch[3] = 'O';
    ch[4] = 'U';

    FORS(cnt,1,6) {
        vector<int> tmp;
        dfs(cnt,tmp);
    }
    sort(v.begin(),v.end());
    FOR(i,v.size()) if(v[i]==word) {
        res=i+1;
        break;
    }
    return res;
}
