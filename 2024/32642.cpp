#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    ll anger = 0, sum = 0;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        anger += (a ? 1 : -1);
        sum += anger;
    }
    cout << sum << '\n';

    return 0;
}