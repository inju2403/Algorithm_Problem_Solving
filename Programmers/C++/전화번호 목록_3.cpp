#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    FORS(i, 1, phone_book.size()) {
        if(phone_book[i].find(phone_book[i-1]) == 0)
            return false;
    }
    
    return true;
}
