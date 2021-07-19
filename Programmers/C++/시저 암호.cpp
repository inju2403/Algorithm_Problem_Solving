#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i=0;i<s.size();++i) {
        if(s[i]==' ') continue;
        if(s[i]+n>'z') s[i]='a'+((n-1)-('z'-s[i]));
        else if(s[i]<'a' && s[i]+n>'Z') s[i]='A'+((n-1)-('Z'-s[i]));
        else s[i]+=n;
    }
    return s;
}
