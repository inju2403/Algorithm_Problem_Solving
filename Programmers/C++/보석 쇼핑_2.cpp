#include <string>
#include <vector>
#include <unordered_map>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
using namespace std;

int l,r,cnt,total,mn=INF;
vector<int> res;
unordered_map<string,int> um;

vector<int> solution(vector<string> gems) {
    
    // 보석 종류 세기
    for(auto x: gems) if(++um[x]==1) ++total;
    um.clear();
    
    // 투포인터
    while(!(r==gems.size() && cnt<total)) {
        if(cnt<total) {
            if(++um[gems[r++]]==1) ++cnt;
        }
        else if(cnt==total) {
            if(mn>r-l) {
                mn=r-l;
                res.clear();
                res.push_back(l+1); res.push_back(r);
            }
            if(--um[gems[l++]]==0) --cnt;
        }
    }
    
    return res;
}
