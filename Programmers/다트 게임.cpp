#include <iostream>
#include <string>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

unordered_map<char,int> um;
int res,idx,n[3],op[3],mul[3]={1,1,1};

int solution(string s) {
    um['S']=1;
    um['D']=2;
    um['T']=3;
    
    FOR(i, s.size()) {
        if(s[i]=='S' || s[i]=='D' || s[i]=='T') {
            int len = 1;
            if(s[i-2]=='1' && s[i-1]=='0') len=2;
            n[idx] = stoi(s.substr(i-len,len));
            op[idx] = um[s[i]];
            
            if(i<s.size()-1) {
                if(s[i+1]=='*') {
                    mul[idx]*=2;
                    mul[idx-1]*=2;
                }
                else if(s[i+1]=='#') {
                    mul[idx]*=-1;
                }
            }
            ++idx;
        }
    }
    
    FOR(i,3) {
        int sum=1;
        FOR(j,op[i]) sum*=n[i];
        sum*=mul[i];
        res+=sum;
        cout<<sum<<endl;
    }
    
    return res;
}
