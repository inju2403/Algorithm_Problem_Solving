#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

struct node {
    string id, message;
};
vector<node> v;
unordered_map<string,string> um;

vector<string> solution(vector<string> record) {
    vector<string> res;
    
    for(auto x: record) {
        vector<string> cur;
        string tmp = "";
        FOR(i, x.size()) {
            if(x[i]==' ') {
                cur.push_back(tmp);
                tmp="";
            }
            else if(i==x.size()-1) cur.push_back(tmp+x[i]);
            else tmp+=x[i];
        }
        if(cur[0]=="Enter") {
            um[cur[1]]=cur[2];
            v.push_back({cur[1],"님이 들어왔습니다."});
        }
        else if(cur[0]=="Leave") {
            v.push_back({cur[1],"님이 나갔습니다."});
        }
        else {
            um[cur[1]]=cur[2];
        }
    }
    
    for(auto x: v) res.push_back(um[x.id]+x.message);
    
    return res;
}
