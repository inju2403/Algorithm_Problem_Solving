#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 10000000
using namespace std;

int res,n,p[MAX];
bool visited[10];
unordered_map<int,bool> um;
string ori;

void getPrime() {
    FORS(i,2,MAX) p[i] = 1;
    for(int i=2; i*i<=MAX; ++i) {
        for(int j = i*i; j<MAX; j+=i) {
            p[j]=0;
        }
    }
}

void dfs(int idx,int sz, string s) {
    if(s.size()==sz) {
        int num = stoi(s);
        if(p[num] && um.count(num)==0) {
            ++res;
            um[num]=1;
        }
        return;
    }
    FOR(i,n) {
        if(visited[i]) continue;
        visited[i] = 1;
        string cur = s + ori[i];
        dfs(i,sz,cur);
        visited[i] = 0;
    }
}

int solution(string numbers) {
    ori = numbers;
    n = numbers.size();
    getPrime();
    string s = "";
    FORS(i,1,numbers.size()+1) dfs(0,i,s);
    return res;
}
