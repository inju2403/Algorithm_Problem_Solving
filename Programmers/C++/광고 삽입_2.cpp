#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 360010

using namespace std;

int t[MAX];
string res;

string go(int k) {
    string s = to_string(k%60); k/=60;
    string m = to_string(k%60); k/=60;
    string h = to_string(k);
    
    if(s.size()==1) s = "0"+s;
    if(m.size()==1) m = "0"+m;
    if(h.size()==1) h = "0"+h;
    
    string ret = h + ":" + m + ":" + s;
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    
    // 1. logs 파싱
    // 2. 시작<=x<끝 t배열에 ++
    // 3. l,r을 이동시키며 sum+=v[++r], sum-=v[l++] && max값이면 res에 삽입
    
    for(string s: logs) {
        vector<string> v;
        string tmp = "";
        for(char c: s) {
            if(c=='-') {
                v.push_back(tmp);
                tmp = "";
            }
            else tmp+=c;
        }
        v.push_back(tmp);
        
        int hh = stoi(v[0].substr(0,2))*3600;
        int mm = stoi(v[0].substr(3,2))*60;
        int ss = stoi(v[0].substr(6,2));
        int st = hh+mm+ss;
        
        hh = stoi(v[1].substr(0,2))*3600;
        mm = stoi(v[1].substr(3,2))*60;
        ss = stoi(v[1].substr(6,2));
        int ed = hh+mm+ss;
        
        FORS(i,st,ed) ++t[i];
    }
    
    int h = stoi(play_time.substr(0,2))*3600;
    int m = stoi(play_time.substr(3,2))*60;
    int s = stoi(play_time.substr(6,2));
    int last = h+m+s;
    
    h = stoi(adv_time.substr(0,2))*3600;
    m = stoi(adv_time.substr(3,2))*60;
    s = stoi(adv_time.substr(6,2));
    int interval = h+m+s;
    
    long long sum = 0;
    FOR(i,interval) sum+=t[i];
    long long mx = sum;
    res = "00:00:00";
    
    int l = 0, r = interval-1;
    while(r<last-1) {
        sum -= t[l++];
        sum += t[++r];
        if(sum > mx) {
            sum = mx;
            res = go(l);
        }
    }
    
    return res;
}
