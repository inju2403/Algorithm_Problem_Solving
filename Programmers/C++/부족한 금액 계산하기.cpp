using namespace std;
typedef long long ll;

long long solution(int price, int money, int count)
{
    ll res = (ll)money - (ll)((count)*(count+1)/2)*price;
    
    return res<0 ? -res : 0;
}
