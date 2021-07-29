#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 105

using namespace std;

struct node {
    int x,y,a;
    
    bool operator < (const node& arg) const {
        if(x!=arg.x) return x<arg.x;
        else if(y!=arg.y) return y<arg.y;
        return a<arg.a;
    }
};

unordered_map<string, bool> um; //x|y|a string으로 해싱
bool chk[MAX][MAX][2]; // [2]: 기둥 밑, 보 왼쪽
string s;

void judge(int x,int y,int a,int b,string s) {
    if(b==1) {
        um[s]=1;
        chk[y][x][a]=1;
    } else {
        um.erase(s);
        chk[y][x][a]=0;
    }
    bool flag = 1;
    
    for(auto next: um) {
        string s = next.first;
        vector<int> v; // x,y,a
        string cur = "";
        FOR(i,s.size()+1) {
            if(i==s.size() || s[i]=='|') {
                v.push_back(stoi(cur));
                cur="";
            } else {
                cur+=s[i];
            }
        }
        int cx = v[0];
        int cy = v[1];
        int ca = v[2];
        if(ca==0) { // 기둥
            if(cy==0 || chk[cy][cx-1][1]+chk[cy][cx][1]>=1 || chk[cy-1][cx][0]==1) continue;
            flag = 0;
            break;
        } else { // 보
            if(chk[cy-1][cx][0]+chk[cy-1][cx+1][0]>=1 || chk[cy][cx-1][1]+chk[cy][cx+1][1]==2) continue;
            flag = 0;
            break;
        }
    }
    if(!flag) {
        if(b==0) {
            um[s]=1;
            chk[y][x][a]=1;
        } else {
            um.erase(s);
            chk[y][x][a]=0;
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> res;
    vector<node> srted;
    
    for(auto next: build_frame) {
        int x = next[0];
        int y = next[1];
        int a = next[2];
        int b = next[3];
        s = to_string(x)+"|"+to_string(y)+"|"+to_string(a);
        
        judge(x,y,a,b,s);
    }
    
    for(auto next: um) {
        string s = next.first;
        vector<int> v;
        string cur = "";
        FOR(i,s.size()+1) {
            if(i==s.size() || s[i]=='|') {
                v.push_back(stoi(cur));
                cur="";
            } else {
                cur+=s[i];
            }
        }
        srted.push_back({v[0],v[1],v[2]});
    }
    sort(srted.begin(), srted.end());
    for(auto next: srted) {
        vector<int> v;
        v.push_back(next.x);
        v.push_back(next.y);
        v.push_back(next.a);
        res.push_back(v);
    }
    
    return res;
}
