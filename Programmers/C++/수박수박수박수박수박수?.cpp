#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
using namespace std;

string solution(int n) {
    string res = "";
    FOR(i,n) i%2? res+="박" : res+="수";
    return res;
}
