#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long k = sqrt(n);
    if(k*k==n) return(k+1)*(k+1);
    return -1;
}
