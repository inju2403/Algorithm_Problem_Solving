#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

vector<string> a,b;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> res;
    
    // 1. 파싱
    for(auto x: arr1) {
        string cur = "";
        while(x) {
            cur+=(x%2)+'0';
            x/=2;
        }
        int cnt = n-cur.size();
        while(cnt--) cur+='0';
        reverse(cur.begin(), cur.end());
        a.push_back(cur);
    }
    
    for(auto x: arr2) {
        string cur = "";
        while(x) {
            cur+=(x%2)+'0';
            x/=2;
        }
        int cnt = n-cur.size();
        while(cnt--) cur+='0';
        reverse(cur.begin(), cur.end());
        b.push_back(cur);
    }
    
    // 합치기
    FOR(i,n) {
        string c = a[i];
        string d = b[i];
        string cur = "";
        FOR(j,n) {
            if(c[j]=='1' || d[j]=='1') cur+='#';
            else cur+=' ';
        }
        res.push_back(cur);
    }
    
    return res;
}
