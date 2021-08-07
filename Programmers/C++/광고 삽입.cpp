#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;
typedef long long ll;

int val,ed,diff,l,r,h,m,s,hh,mm,ss,t[360000];
ll mx,total;
string sss,mmm,hhh,res;

string solution(string play_time, string adv_time, vector<string> logs) {

    hh = stoi(play_time.substr(0,2));
    mm = stoi(play_time.substr(3,2));
    ss = stoi(play_time.substr(6,2));
    ed = hh*3600+mm*60+ss;

    hh = stoi(adv_time.substr(0,2));
    mm = stoi(adv_time.substr(3,2));
    ss = stoi(adv_time.substr(6,2));
    diff = hh*3600+mm*60+ss;

    for(string x: logs) {
        h = stoi(x.substr(0,2));
        m = stoi(x.substr(3,2));
        s = stoi(x.substr(6,2));
        ll src = h*3600+m*60+s;

        hh = stoi(x.substr(9,2));
        mm = stoi(x.substr(12,2));
        ss = stoi(x.substr(15,2));
        ll sink = hh*3600+mm*60+ss;

        FORS(i,src,sink) ++t[i]; // 1~5 (4초) -> 1,2,3,4 배열 체크
    }
    l = 0;
    r = diff;
    FORS(i,l,r) total+=t[i];
    mx = total;
    val = l;

    while(r<ed) {
        total -= t[l++];
        total += t[r++];
        if(mx < total) {
            mx = total;
            val = l;
        }
    }

    sss = to_string(val%60); val/=60;
    mmm = to_string(val%60); val/=60;
    hhh = to_string(val);

    if(sss.size()==1) sss = "0"+sss;
    if(mmm.size()==1) mmm = "0"+mmm;
    if(hhh.size()==1) hhh = "0"+hhh;

    res = hhh + ":" + mmm + ":" + sss;
    return res;
}
