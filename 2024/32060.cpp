#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

struct Data
{
    ll num, two;
    bool operator < (const Data &o) const{
        if(two == o.two) return num > o.num;
        return two > o.two;
    }
};

priority_queue<Data, vector<Data>> pq;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        ll a; cin >> a;
        ll tmp = a, cnt = 0;
        while(tmp % 2 == 0){
            tmp /= 2;
            cnt++;
        }
        pq.push({a, cnt});
    }

    while(pq.size() > 1){
        Data a = pq.top(); pq.pop();
        Data b = pq.top(); pq.pop();
        ll tmp = __gcd(a.num, b.num), mn = min(a.two, b.two);
        pq.push({tmp * 2, mn + 1});
    }

    cout << pq.top().num << '\n';

    return 0;
}