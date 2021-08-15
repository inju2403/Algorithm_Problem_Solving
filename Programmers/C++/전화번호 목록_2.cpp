#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    FOR(i, phone_book.size()-1) {
        if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].size()))
            return false;
    }
    
    return true;
}
