#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int w,h;

int solution(vector<vector<int>> sizes) {
    for(auto v: sizes) {
        if(v[0]<v[1]) swap(v[0],v[1]);
        w=max(w,v[0]);
        h=max(h,v[1]);
    }
    return w*h;
}
