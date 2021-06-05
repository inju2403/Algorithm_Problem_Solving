#include <vector>
#include <iostream>

using namespace std;

int pre=-1;

vector<int> solution(vector<int> arr)
{
    vector<int> res;
    for(auto x: arr) {
        if(x==pre) continue;
        res.push_back(x);
        pre=x;
    }
    return res;
}
