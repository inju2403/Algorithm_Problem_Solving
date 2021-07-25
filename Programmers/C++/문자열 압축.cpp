#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321

using namespace std;

string res,cur;
int num,mn=INF;

int solution(string s) {
    if(s.size()==1) return 1;
    
    FORS(i,1,s.size()/2+1) {
        res="";
        cur = s.substr(0,i);
        num=1;
        for(int j=i;j<s.size();j+=i) {
            string tmp = s.substr(j,i);
            if(cur==tmp) {
                ++num;
            }
            else {
                if(num>1) res+=to_string(num)+cur;
                else res+=cur;
                cur=tmp;
                num=1;
            }
        }
        if(num>1) res+=to_string(num)+cur;
        else res+=cur;
        mn=min(mn,(int)res.size());
    }
    
    return mn;
}
