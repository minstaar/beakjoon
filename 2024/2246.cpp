#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<pii> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end());
    int ans = 0, cost = 1e9;
    for(int i=0; i<N; i++){
        if(arr[i].second < cost){
            cost = arr[i].second;
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}