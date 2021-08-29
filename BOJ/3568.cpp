#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define LINF 9123456789123456789
#define MAX 21
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

string input;
vector<string> v,res;
unordered_map<string, string> um;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    getline(cin, input);
    string cur = "";
    for(auto c: input) {
        if(c==' ') {
            v.push_back(cur);
            cur="";
        }
        else cur += c;
    }
    v.push_back(cur);
    FORS(i,1,v.size()) {
        string s = v[i];
        string a = "", b = "";
        FOR(i,s.size()) {
            if(!((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) {
                a = s.substr(0,i);
                string k = s.substr(i,s.size()-i-1);
                reverse(k.begin(), k.end());
                FOR(i,k.size()) {
                    if(k[i]==']') {
                        b+="[]";
                        ++i;
                    }
                    else b+=k[i];
                }
                break;
            }
        }
        um[a]=b;
        res.push_back(a);
    }
    FOR(i,res.size()) {
        cout<<v[0]<<um[res[i]]<<" "<<res[i]<<";\n";
    }
}
