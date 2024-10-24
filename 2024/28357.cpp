#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int N; ll K;
ll arr[500010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    sort(arr, arr + N, greater<>());
    ll ans, sum = 0;
    ans = arr[0];
    for(int i=1; i<=N; i++){
        if((arr[i-1] - arr[i]) * i <= K - sum){
            sum += (arr[i-1] - arr[i]) * i;
            ans = arr[i];
        }
        else{
            ans = arr[i-1] - (K - sum) / i;
            break;
        }
    }

    cout << ans << '\n';

    return 0; 
}