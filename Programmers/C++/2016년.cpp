#include <string>
#include <vector>

using namespace std;

int cnt[13]={0,0,31,60,91,121,152,182,213,244,274,305,335};
string s[7]={"FRI","SAT","SUN","MON","TUE","WED","THU"};

string solution(int a, int b) {
    return s[(cnt[a]+b-1)%7];
}
