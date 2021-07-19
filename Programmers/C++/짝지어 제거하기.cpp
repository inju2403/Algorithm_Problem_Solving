#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> v;

int solution(string s)
{
    for(auto x: s) {
        if(v.empty()) v.push_back(x);
        else {
            v.back()==x? v.pop_back() : v.push_back(x);
        }
    }

    return v.size()==0? 1 : 0;
}
