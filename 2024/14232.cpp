#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

bool check[1000010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<ll> prime;
    for(int i=2; i<=1000000; i++){
        if(!check[i]){
            prime.push_back(i);
            for(int j=i*2; j<=1000000; j+=i) check[j] = true;
        }
    }

    ll x; cin >> x;
    vector<ll> res;
    for(auto i: prime){
        while(x % i == 0){
            res.push_back(i);
            x /= i;
        }
        if(x == 1) break;
    }

    if(x != 1) res.push_back(x);
    cout << res.size() << '\n';
    for(auto i: res) cout << i << ' ';

    return 0;
}