#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;
typedef pair<int,int> pii;

int num=1;
unordered_map<int,pii> um;
string s;
pii l={3,0}, r={3,2};

int dist(pii a, pii b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

void doL(int x) {
    l=um[x];
    s+="L";
}

void doR(int x) {
    r=um[x];
    s+="R";
}

string solution(vector<int> numbers, string hand) {
    FOR(y,3) FOR(x,3) um[num++]={y,x};
    um[0]={3,1};
    
    for(auto x: numbers) {
        if(x==1 || x==4 || x==7) doL(x);
        else if(x==3 || x==6 || x==9) doR(x);
        else {
            if(dist(l,um[x])==dist(r,um[x])) {
                if(hand=="left") doL(x);
                else doR(x);
            }
            else dist(l,um[x])<dist(r,um[x])? doL(x) : doR(x);
        }
    }
    
    return s;
}
