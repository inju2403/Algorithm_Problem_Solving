#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int num=1;
string s = "0";

string convert(int n, int x) {
    string ret = "";
    while(x) {
        int cur = x%n;
        if(cur==10 && 10<n) ret += 'A';
        else if(cur==11 && 11<n) ret += 'B';
        else if(cur==12 && 12<n) ret += 'C';
        else if(cur==13 && 13<n) ret += 'D';
        else if(cur==14 && 14<n) ret += 'E';
        else if(cur==15 && 15<n) ret += 'F';
        else ret+=to_string(cur);
        x/=n;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string solution(int n, int t, int m, int p) {
    string res = "";
    
    while(s.size()<=t*m) {
        s+=convert(n, num++);
    }
    cout<<s<<endl;
    
    int cnt = 0;
    
    for(int i=0; cnt<t; i+=m,++cnt) {
        res+=s[i+p-1];
    }
    
    return res;
}
