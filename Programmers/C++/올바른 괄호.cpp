#include <string>
#include <iostream>

using namespace std;

int n;

bool solution(string s)
{
    for(auto c: s) {
        if(c=='(') ++n;
        else {
            if(--n<0) return false;
        }
    }

    return n==0? true : false;
}
