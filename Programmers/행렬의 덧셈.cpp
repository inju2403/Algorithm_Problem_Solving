#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr1[0].size(), 0));
    FOR(i, arr1.size()) FOR(j, arr1[0].size()) answer[i][j]=arr1[i][j]+arr2[i][j];
    return answer;
}
