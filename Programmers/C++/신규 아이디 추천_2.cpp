#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

string res;

string solution(string id) {
    
    // 1
    FOR(i, id.size()) {
        if(id[i]>='A' && id[i]<='Z') id[i] += 'a'-'A';
    }
    
    //2
    for(auto c: id) {
        if((c>='a' && c<='z')
          || (c>='0' && c<='9')
          || (c=='-')
          || (c=='_')
          || (c=='.')) {
            res+=c;
        }
    }
    
    //3
    id = res;
    res = "";
    res+=id[0];
    FORS(i, 1, id.size()) {
        if(id[i]=='.' && id[i-1]=='.') continue;
        res+=id[i];
    }
    
    //4
    id = res;
    res = "";
    int st=0, ed=id.size();
    if(id[st]=='.') ++st;
    if(id[ed-1]=='.') --ed;
    FORS(i,st,ed) res+=id[i];
    
    //5
    if(res=="") res="a";
    
    //6
    if(res.size()>=16) res = res.substr(0,15);
    if(res[res.size()-1]=='.') res.pop_back();
    
    //7
    char c = res.back();
    while(res.size()<=2) res+=c;
    
    return res;
}
