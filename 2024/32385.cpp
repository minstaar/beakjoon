#include <iostream>
#include <vector>
using  namespace std;
using ll = long long;

vector<ll> res;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N; cin >> N;
    ll a = 1;
    for(int i=1; i<N; i+=2){
        res.push_back(a);
        res.push_back(-a);
        a++;
    }
    if(N % 2){
        res.push_back(N * N);
        res.push_back(N);
    }
    else{
        res.push_back(0);
    }
    for(int i=0; i<=N; i++) cout << res[i] << ' ';

    return 0;
}