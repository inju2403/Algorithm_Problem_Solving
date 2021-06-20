#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int l = phone_number.length();
    string answer = "";
    for(int i=0;i<l;++i) {
        if(i<l-4) answer += "*";
        else answer += phone_number[i];
    }
    return answer;
}
