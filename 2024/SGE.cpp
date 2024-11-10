#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int N;
ll arr[200010], sum;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){cin >> arr[i]; sum += arr[i];}
    sort(arr, arr + N);
    
    ll tmp1 = sum - (arr[0] + arr[1]) + 2 * arr[0] * arr[1];
    ll tmp2 = sum - (arr[N-1] + arr[N-2]) + 2 * arr[N-1] * arr[N-2];

    cout << max({sum, tmp1, tmp2}) << '\n';

    return 0;
}