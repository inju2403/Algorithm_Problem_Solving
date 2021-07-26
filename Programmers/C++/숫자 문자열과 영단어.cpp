#include <string>
#include <vector>
#define FOR(i,n) for(int i=0;i<(n);++i)
using namespace std;

int solution(string s) {
    string res="";
    FOR(i,s.size()) {
        char ch = s[i];
        if(ch=='z') {
            res+='0';
            i+=3;
        }
        else if(ch=='o') {
            res+='1';
            i+=2;
        }
        else if(ch=='t') {
            if(s[i+1]=='w') {
                res+='2';
                i+=2;
            }
            else res+='3', i+=4;
        }
        else if(ch=='f') {
            if(s[i+1]=='o') res+='4';
            else res+='5';
            i+=3;
        }
        else if(ch=='s') {
            if(s[i+1]=='i') {
                res+='6';
                i+=2;
            }
            else res+='7', i+=4;
        }
        else if(ch=='e') res+='8', i+=4;
        else if(ch=='n') res+='9', i+=3;
        else res+=ch;
    }
    return stoi(res);
}
