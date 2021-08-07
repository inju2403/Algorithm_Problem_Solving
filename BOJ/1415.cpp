#include<iostream>
#include<vector>
#include<algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
using namespace std;

int n,a[55],c[10005],s[500004],cnt,z=1;
long long sum, d[500005];
vector<int> v;

int main() {
    cin >> n;
    FOR(i, n) {
        cin >> a[i];
        if (!a[i]) ++z;
        else {
            if (c[a[i]] == 0) {
                v.push_back(a[i]);
                ++cnt;
            }
            ++c[a[i]];
        }
    }
    sort(v.begin(), v.end());
    d[0] = 1;
    FOR(i, cnt) {
        for (int j = 500000; j >= 0; --j) {
            FOR(k, c[v[i]]) {
                if (j - (k+1) * v[i] < 0) break;
                d[j] += d[j - (k+1) * v[i]];
            }
        }
    }
    FOR(i, 500002) s[i] = 1;
    for (int i = 2; i*i <= 500001; ++i) {
        if (s[i] == 0) continue;
        for (int j = i * i; j <= 500001; j += i) {
            s[j] = 0;
        }
    }
    for (int i = 2; i < 500002;++i) if (s[i]) sum += d[i];
    cout << z*sum;
}
