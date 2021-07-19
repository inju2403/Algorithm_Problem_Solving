#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int num=1;
string s = "0";
char arr[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string convert(int n, int x) {
    string ret = "";
    while(x) {
        ret += arr[x%n];
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
