#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

bool comp(int a, int b) {
    return to_string(a)+to_string(b) > to_string(b)+to_string(a);
}

string solution(vector<int> v) {
    sort(v.begin(),v.end(),comp);
    string s = "";
    for(auto x: v) s+=to_string(x);
    if(s.size()>=2 && s[0]=='0' && s[s.size()-1]=='0') return "0";
    return s;
}
