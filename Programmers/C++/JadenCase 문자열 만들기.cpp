#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

string res;
bool chk;

string solution(string k) {

    FOR(i,k.size()) {
        if(!chk) {
            if(k[i]>='a' && k[i]<='z') res += k[i] - 'a' +'A';
            else res += k[i];
            if(k[i]!=' ') chk = 1;
        }
        else {
            if(k[i]>='A' && k[i]<='Z') res += k[i] - 'A' +'a';
            else res += k[i];
            if(k[i]==' ') chk = 0;
        }
    }
    return res;
}
