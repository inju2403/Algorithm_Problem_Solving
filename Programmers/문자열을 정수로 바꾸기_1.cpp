#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int res=0,n=1;
    for(int i=s.size()-1;i>=1;--i) {
        res+=(s[i]-'0')*n;
        n*=10;
    }
    if(s[0]=='-') res=-res;
    else if(s[0]!='+') res+=(s[0]-'0')*n;
    return res;
}
