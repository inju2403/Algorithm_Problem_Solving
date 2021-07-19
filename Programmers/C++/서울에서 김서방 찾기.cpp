#include <string>
#include <vector>

using namespace std;

int idx;

string solution(vector<string> seoul) {
    for(int i=0;i<seoul.size();++i) if(seoul[i]=="Kim") idx=i;
    return "김서방은 "+to_string(idx)+"에 있다";
}
