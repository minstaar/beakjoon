#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<ll> res;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    n++;
    res.push_back(1);
    for(ll i=2; i*i<=n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    for(auto x: res) cout << x << ' ';

    return 0;
}