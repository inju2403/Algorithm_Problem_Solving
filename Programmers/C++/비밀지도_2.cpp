#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> res;
    
    FOR(i,n) {
        string cur = "";
        arr1[i] = arr1[i] | arr2[i];
        FOR(j,n) {
            arr1[i]%2? cur="#"+cur : cur=" "+cur;
            arr1[i]>>=1;
        }
        res.push_back(cur);
    }
    
    return res;
}
