#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end(), greater<>());
    ll sum = arr[0], cnt = 1;
    for(int i=1; i<N; i++){
        if((sum + arr[i]) * (cnt + 1) < sum * cnt + arr[i]) break;
        sum += arr[i];
        cnt++;
    }

    sum *= cnt;
    for(int i=cnt; i<N; i++) sum += arr[i];

    cout << sum << '\n';

    return 0;
}