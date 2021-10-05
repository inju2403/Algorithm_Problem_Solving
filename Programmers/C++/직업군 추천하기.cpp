#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

int mx;
string res;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    for(auto str: table) {
        vector<string> v;
        string tmp = "";
        for(auto c: str) {
            if(c==' ') {
                v.push_back(tmp);
                tmp = "";
            }
            else tmp += c;
        }
        v.push_back(tmp);
        int sum = 0;
        FOR(i,languages.size()) {
            string s = languages[i];
            int num = preference[i];
            bool chk = false;
            FORS(j,1,v.size()) {
                string k = v[j];
                if(s==k) {
                    chk = true;
                    num *= v.size() - j;
                    break;
                }
            }
            if(chk == false) num = 0;
            sum += num;
        }
        if(mx <= sum) {
            if(mx < sum) res = v[0];
            else if(res > v[0]) res = v[0];
            mx = sum;
        }
    }
    return res;
}
