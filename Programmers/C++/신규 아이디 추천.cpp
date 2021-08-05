#include <iostream>
#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

string solution(string new_id) {
    string res = "";
    
    //1
    FOR(i,new_id.size()) {
        if(new_id[i]>='A' && new_id[i]<='Z') new_id[i]+='a'-'A';
    }
    //2
    for(auto x: new_id) {
        if((x>='a' && x<='z')||(x>='0' && x<='9')||x=='-'||x=='_'||x=='.') {
            res+=x;
        }
    }
    new_id = res;
    res = "";
    res += new_id[0];
    //3
    FORS(i,1,new_id.size()) {
        if(new_id[i-1]=='.' && new_id[i]=='.') continue;
        res+=new_id[i];
    }
    //4
    if(res[0]=='.') res = res.substr(1,res.size()-1);
    if(res[res.size()-1]=='.') res = res.substr(0,res.size()-1);
    //5
    if(res.empty()) res="a";
    //6
    if(res.size()>=16) res = res.substr(0,15);
    if(res[res.size()-1]=='.') res = res.substr(0,res.size()-1);
    //7
    char c = res[res.size()-1];
    while(res.size()<=2) res+=c;
    return res;
}
