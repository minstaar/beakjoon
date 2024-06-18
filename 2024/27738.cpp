#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N; cin >> N;
    ll res = 0;
    vector<int> arr(6);
    for(int i=0; i<6; i++) cin >> arr[i];
    ll idx = N / (arr[5]) * arr[5];
    for(ll i=idx+1; i<=N; i++){
        for(int j=0; j<6; j++){
            if(i % arr[j] == 0){
                if(j == 0) res += i;
                else if(j == 1) res %= i;
                else if(j == 2) res &= i;
                else if(j == 3) res ^= i;
                else if(j == 4) res |= i;
                else res >>= i;
            }
        }
    }
    cout << res << '\n';

    return 0;
}