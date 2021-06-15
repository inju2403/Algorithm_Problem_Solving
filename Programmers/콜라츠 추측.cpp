#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long k = (long long) num;
    while(k!=1) {
        if(k%2==0) k/=2;
        else k=k*3+1;
        ++answer;
        if(answer==500) return -1;
    }
    return answer;
}
