#include <string>
#include <vector>

using namespace std;

int ori,k;

bool solution(int x) {
    ori=x;
    while(x) {
        k+=x%10;
        x/=10;
    }
    return ori%k? false : true;
}
