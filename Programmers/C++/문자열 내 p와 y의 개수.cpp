#include <string>
#include <iostream>
using namespace std;

int cnt[2];
bool solution(string s)
{
    for(auto x: s) {
        if(x=='p'|| x=='P') cnt[0]++;
        else if(x=='y' || x=='Y') cnt[1]++;
    }

    return cnt[0]==cnt[1]? true : false;
}
