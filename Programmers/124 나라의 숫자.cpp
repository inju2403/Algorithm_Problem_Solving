#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string res = "";
    
    string a[3] = {"4", "1", "2"};
    while(n) {
        res+=a[n%3];
        n%3==0? n=n/3-1 : n/=3;
    }
    reverse(res.begin(), res.end());
    return res;
}
