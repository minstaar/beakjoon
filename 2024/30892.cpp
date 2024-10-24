#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;

int N, K;
ll T;
multiset<ll> s;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K >> T;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        s.insert(a);
    }
    for(int i=0; i<K; i++){
        auto it = s.lower_bound(T);
        if(it != s.begin()){
            it--;
            T += *it;
            s.erase(it);
        }
    }
    cout << T << '\n';

    return 0;
}